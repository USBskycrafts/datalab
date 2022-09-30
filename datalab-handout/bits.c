/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Junran Yang JYQ3198
 * Isabella Wu ipw8296
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */

/* Comment:`
 * -1 could be express in  2's complement as 11111...1111,
 * which means we can negate 0 to get this. 
 */
int minusOne(void) {
  return ~0;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */

/*
 * max positive number is 0x7fffffff 
 * so negative x we would get 0x80000000, which equals to (1 << 31)
 */
int isTmax(int x) {
  return ~x == (1 << 31);
}
/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */

/*
 * -x = ~x + 1, we use xor operation to compare 
 * whether they are same
 */
int distinctNegation(int x) {
  return !!((~x + 1) ^ x);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
      x - y > 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

/*
 * we use mask to check whether x and y is the same sign
 * if the same, we can use y - x to check if y >= x it is 0, and it is 1 in contrast
 * if not the same, we need to find which one is positive and which one is negative
 */
int isGreater(int x, int y) {
  int mask = (x ^ y) >> 31;
  return ((y >> 31) & 1 & mask) | ((y + ~x + 1) >> 31) & !mask;
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */

/*
 * ~(x | y) == ~x & ~y, a conclusion from discrete maths
 */
int bitOr(int x, int y) {
  return ~(~x & ~y);
}
/* 
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and & 
 *   Example: bitMatch(0x7, 0xfffffffE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */

/*
 * we can use xor to generate the answer
 * and x ^ y = (x & ~y) | (~x & y)
 */
int bitMatch(int x, int y) {
  return ~(x & ~y | ~x & y);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    int mask = 0xaa;
    mask = mask ^ (mask << 8);
    mask = mask ^ (mask << 16);
    /*
     * we use this way to construct 0xaaaaaaaa, by copy 1 to the odd position
     */
    return !!(mask & x);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xff;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

/*
 * ~0 + 1 = 0, ~1 + 1 = 1
 * to guarantee x can only be 1 or 0, we use !!x
 */
int conditional(int x, int y, int z) {
  return (((~(!(!x))) + 1) & y) | (((~(!x)) + 1) & z);
}
/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */

/*
 *  swap the position from a small, sub problem to the big, whole problem
 *  first we only swap the number on odd postion and even position
 *  then, we combine two number as a group, and swap even and odd group position as well
 *  then, we combine the two adjacent group into one group, and repeat the procedure above
 */
int isPallindrome(int x) {
    int mask_1 = 0x55 << 8 | 0x55; 
    int mask_2 = 0x33 << 8 | 0x33; 
    int mask_3 = 0x0f << 8 | 0x0f; 
    int mask_4 = 0xff;
    int mask_5 = 0xff << 8 | 0xff;
    int temp = x;
    
    temp = ((temp & mask_1) << 1) | ((temp >> 1) & mask_1);
    temp = ((temp & mask_2) << 2) | ((temp >> 2) & mask_2);
    temp = ((temp & mask_3) << 4) | ((temp >> 4) & mask_3);
    temp = ((temp & mask_4) << 8) | ((temp >> 8) & mask_4);
    temp &= mask_5;
    x = (x >> 16) & mask_5;
    return !(temp ^ x);	 
}
/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
    unsigned int f = uf & ~(1 << 31), g = ug & ~(1 << 31);
    if(f == 0 && g == 0) return 1;

    unsigned exp_mask = (~0) << 23;
    exp_mask = exp_mask & ~(1 << 31);

    unsigned frac_mask = (~0) << 9;
    frac_mask = frac_mask >> 9;
    if(((f & exp_mask) == exp_mask && (f & frac_mask)) || ((g & exp_mask) == exp_mask && (g & frac_mask))) return 0;
    // ↑ figure out whether they are +0, -0 || NAN || INF
    return uf == ug;
}
/* 
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
 
 /*
  * if it is a norm float, then we just minus one one exp position
  * if exp <= 1, then we only right shift the frac position
  */
unsigned floatScale1d2(unsigned uf) {
    unsigned exp_mask = ((~0) << 23) & ~(1 << 31), frac_mask = ((~(1 << 23)) << 8) >> 8;
    int exp = (uf & exp_mask) >> 23;
    int s = uf & (1 << 31);
    if((uf & ~(1 << 31)) >= exp_mask) return uf;
    if(exp > 1) return (uf & ~exp_mask) | (--exp) << 23;
    if((uf & 3) == 3) uf = uf + 2;
    return ((uf >> 1) & frac_mask) | s;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int exp = x + 127;
    if(exp <= 0) return 0;
    if(exp >= 255) return ((~0) << 23) & ~(1 << 31);
    return exp << 23;
}
