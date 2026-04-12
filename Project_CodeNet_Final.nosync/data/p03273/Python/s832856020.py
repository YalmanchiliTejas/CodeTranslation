#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# FileName: 	B
# CreatedDate:  2020-06-26 20:42:26 +0900
# LastModified: 2020-07-20 04:38:38 +0900
#


import os
import sys
import numpy as np
# import pandas as pd


def main():
    h, w = map(int, input().split())
    a = np.zeros((h,w), dtype = np.int32)
    for i in range(h):
        s = input()
        for j in range(w):
            if s[j] == '.':
                a[i, j] = 1
    stack = []
    delete_colums = 0
    delete_index = 0
    for i in range(h):
        if np.sum(a[i, :]) == w:
            stack.append(i)
            delete_index += 1
    while stack:
        p = stack.pop()
        a = np.delete(a, obj=p, axis=0)

    for i in range(w):
        if np.sum(a[:, i]) == h-delete_index:
            stack.append(i)
            delete_colums += 1
    while stack:
        p = stack.pop()
        a = np.delete(a, obj=p, axis=1)
    
    for i in range(h-delete_index):
        for j in range(w-delete_colums):
            if a[i, j] == 0:
                print('#', end='')
            else:
                print('.', end='')
        print()
            



if __name__ == "__main__":
    main()
