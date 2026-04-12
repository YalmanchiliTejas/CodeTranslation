#!/usr/bin/env python3

import sys, math, copy
# import fractions, itertools
# import numpy as np
# import scipy

HUGE = 2147483647
HUGEL = 9223372036854775807
ABC = "abcdefghijklmnopqrstuvwxyz"

def main():
    h, w = map(int, input().split())
    su = 0
    for i in range(h):
        line = input()
        su += line.count("#")
    print("Possible" if su == h + w - 1 else "Impossible")

main()
