#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# FileName: 	C_fix_2
# CreatedDate:  2020-08-29 22:01:34 +0900
# LastModified: 2020-08-29 22:07:06 +0900
#


import os
import sys
import numpy as np
# import pandas as pd


def main():
    n = int(input())
    A = list(map(int, input().split()))
    amari = 1000000007
    ans = ((sum(A))*(sum(A)) - sum(a**2 for a in A))
    print(ans//2%amari)


if __name__ == "__main__":
    main()
