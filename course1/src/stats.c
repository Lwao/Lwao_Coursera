/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Main file for assignment ESE-C1-M1
 *
 * Main file for Week 1 assignment from Introduction to 
 * Embedded Systems Software and Development Environments
 * Course in Coursera
 *
 * @author Levy Gabriel da S. G.
 * @date Frebruary 4, 2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("1 - Print original array: ");
  print_array(test, SIZE);
  printf("2 - Print sorted array: ");
  print_array(sort_array(test,SIZE), SIZE);
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char * data, unsigned length){
  printf("3 - Median  = %.4f\n", find_median(data, length));
  printf("4 - Mean    = %.4f\n", find_mean(data, length));
  printf("5 - Maximum = %d\n", find_maximum(data, length));
  printf("6 - Minimum = %d\n", find_minimum(data, length));
}

#ifdef VERBOSE
void print_array(unsigned char * data, unsigned length){
  for(unsigned i=0; i<length; i++){
    printf("%d ", data[i]);
  }
  printf("\n\n");
}
#endif

float find_median(unsigned char * data, unsigned length){
  float median;
  data = sort_array(data, length);
  if(length % 2 == 0){// array with even length
    median = (data[length/2] + data[length/2-1])/2;
  } else{// array with odd length
    median = data[length/2];
  }

}


float find_mean(unsigned char * data, unsigned length){
  float sum=0.0;
  for(unsigned i=0; i<length; i++){sum += data[i];}
  return sum/length;
}


unsigned find_maximum(unsigned char * data, unsigned length){
  unsigned max=0;
  for(unsigned i=0; i<length; i++){
    if(data[i]>max){max = data[i];}
  }
  return max;
}


unsigned find_minimum(unsigned char * data, unsigned length){
  unsigned min=data[0];
  for(unsigned i=1; i<length; i++){
    if(data[i]<min){min = data[i];}
  }
  return min;
}


unsigned char * sort_array(unsigned char * data, unsigned length){
  for(unsigned i=length; i>0; i--){
    for(unsigned j=0; j<i-1; j++){
      if(data[j]>data[j+1]){
        unsigned char temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }
  return data;
}