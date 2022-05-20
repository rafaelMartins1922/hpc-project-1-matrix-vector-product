# HPC project 1 - Matrix-vector product
Project created for the first in the High Performance Computing class of the Computer and Information Engineering course at Federal University of Rio de Janeiro.

This repo contains the code and text files for a simple program tham multiplies a matrix os size n^2 and a vector of size n, for values of n of 1000, 2000, ..., 15000. The program uses a nested loop to iterate through the vectors and matrices and stores the values of n and their respective times of execution for the loop in text files. The main idea is to check the performance of such operation in C and Fortran, and compare performance when the loop order is inverted (major-row vs major-column orders).
