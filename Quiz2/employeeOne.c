#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrtoConstEmployee ptr, int tableSize, long targetNumber){
    const PtrtoConstEmployee endPtr = ptr+tableSize;
    for(; ptr < endPtr; ptr++){
        if(ptr->number == targetNumber) return (PtrToEmployee)ptr;
    }
    return NULL;
}