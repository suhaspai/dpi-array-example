// C++ Code (dpi.cpp)
// This is the C++ code that will be called from the SystemVerilog module.

#include <iostream>
#include <string.h>
#include "svdpi.h"

svLogicVecVal     sv_logic_vec_a_copy[4];
int               int_a_copy[4];

extern "C" void  dpi_input(const svLogicVecVal *sv_logic_vec_a, const svOpenArrayHandle int_a)
{
   printf("\nHello from C DPI function!\n");

   memcpy(&sv_logic_vec_a_copy, sv_logic_vec_a, sizeof(sv_logic_vec_a_copy) );
   for (int index = 0; index < 4; index++)
      printf("logic_vec_a[%d] => aval = %08x bval = %08x\n", index, (int) sv_logic_vec_a_copy[index].aval, (int) sv_logic_vec_a_copy[index].bval );

   // use accessor functions to find array parameters
   int d = svDimensions(int_a);          // array dimension
   int s = svSize(int_a, 1);             // array size
   int l = svLow(int_a, 1);   
   int h = svHigh(int_a, 1);
   int e = svSizeOfArray(int_a);         // elements size
   void *basePtr = svGetArrayPtr(int_a);
   printf("dimension=%d, array-size=%d, lo_index=%d, hi_index=%d, elemSize=%d\n", d, s, l, h, e);
   for (int index = l; index <= h; index++)
   {
      int_a_copy[index] = *((int *) svGetArrElemPtr1(int_a, index));
      printf("int_a[%2d] = %d\n", index, int_a_copy[index] );
   }

   return;
} 

extern "C" void  dpi_output(svLogicVecVal *sv_logic_vec_a)
{
   memcpy(sv_logic_vec_a, sv_logic_vec_a_copy, sizeof(sv_logic_vec_a_copy) );
}   
