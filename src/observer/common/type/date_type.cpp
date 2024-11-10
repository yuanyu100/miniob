#include<iomanip>

#include"common/lang/comparator.h"
#include"common/lang/sstream.h"
#include"common/log/log.h"
#include"common/type/date_type.h"
#include"common/value.h"

int DateType::compare(const Value &left,const Value &right) const
{
    return common::compare_int((void*)&left.value_.int_value_,(void*)&right.value_.int_value_);
}

RC DateType::to_string(const Value &val,string &result) const{
    stringstream ss;
    ss<<std::setw(4)<<std::setfill('0')<<val.value_.int_value_/10000<<"-"
        <<std::setw(2)<<std::setfill('0')<<(val.value_.int_value_%10000)/100<<"-"
        <<std::setw(2)<<std::setfill('0')<<val.value_.int_value_%100;
    result=ss.str();
    return RC::SUCCESS;
}