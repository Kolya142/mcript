#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif
#define i8 int8_t
#define i16 int16_t
#define i32 int
#define i64 long
#define i128 long long
#define u0 void
#define u8 char
#define u16 uint16_t
#define u32 uint
#define u64 ulong
#define u128 ulong long
#define I8 i8
#define I16 i16
#define I32 i32
#define I64 i64
#define I128 i128
#define U0 u0
#define U8 u8
#define U16 u16
#define U32 u32
#define U64 u64
#define U128 u128
#define nil NULL
#define ret return
#define alloc(T, S) (T*)malloc(sizeof(T)*S)
#define pbegin Nabs::PFunc profiler_wrap = Nabs::PBegin(__FILE__, __FUNCTION__, __LINE__)
#define pend Nabs::PEnd(profiler_wrap)
#define ppbegin Nabs::PClear()
#define str u8*

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#
int main(int argc, char** argv) {
if( argc != 2 ){
printf("usage: %s <mcript code>", argv[0]);
ret 1;
}
i16 *cells = alloc(i16, 100);
for (i16 i = 0; i < 100; i++) {
cells[i] = 0;
}
U16 pc = 0;
U16 cc = 0;
U32 prog_size = strlen(argv[1]);
const str prog = argv[1];
for (;;) {
switch (prog[pc]) {
case '[':;
cc --;
break;
case ']':;
cc ++;
break;
case '+':;
cells[cc] ++;
break;
case '4':;
cells[cc] += 2;
break;
case '-':;
cells[cc] --;
break;
case 'p':;
printf("%d", cells[cc]);
break;
case 'c':;
putchar(cells[cc]);
break;
case '1':;
cells[cc] *= cells[cc+1];
break;
case 'j':;
if( cells[cc] == 0 ){
pc = cells[cc+1];
}
break;
case 'g':;
pc = cells[cc];
break;
case 'h':;
ret 0;
break;
default:;
printf("incorrect instruction '%c'", prog[pc]);
ret 1;
break;
}
pc ++;
}
free(cells);
ret 0;
}
