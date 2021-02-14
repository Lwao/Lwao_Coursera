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
 * @file stats.h
 * @brief Header file for assignment ESE-C1-M1
 *
 * Header file for Week 1 assignment from Introduction to 
 * Embedded Systems Software and Development Environments
 * Course in Coursera
 *
 * @author Levy Gabriel da S. G.
 * @date February 7 2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints statistics
 *
 * Function that prints main statistics parameters from array
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return void
 */
void print_statistics(unsigned char * data, unsigned length);

/**
 * @brief Prints array
 *
 * Function that prints array content
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return void
 */
void print_array(unsigned char * data, unsigned length);

/**
 * @brief Returns median value
 *
 * Compute median of given array
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return median value of data array
 */
float find_median(unsigned char * data, unsigned length);

/**
 * @brief Returns mean value
 *
 * Compute mean of given array
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return mean value of data array
 */
float find_mean(unsigned char * data, unsigned length);

/**
 * @brief Returns max. value
 *
 * Compute maximum value of given array
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return maximum value of data array
 */
unsigned find_maximum(unsigned char * data, unsigned length);

/**
 * @brief Returns min. value
 *
 * Compute minimum value of given array
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return minimum value of data array
 */
unsigned find_minimum(unsigned char * data, unsigned length);

/**
 * @brief Sorts array
 *
 * Sorts array in descendent order (first element largest, last element smallest)
 *
 * @param data, char array to be analyzed
 * @param length, length of data array
 *
 * @return pointer to sorted array
 */
unsigned char * sort_array(unsigned char * data, unsigned length);

#endif /* __STATS_H__ */
