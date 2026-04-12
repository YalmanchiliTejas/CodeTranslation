#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=tf-8
#

"""
"""

from collections import defaultdict
from itertools import accumulate
import bisect

import sys
input = sys.stdin.readline

def solve(a):
    b = a.copy()
    b.reverse()
    c = list(accumulate(b))
    ans = 0
    modulo = 10**9 + 7
    n = len(a)
    for i, aa in enumerate(a[:-1]):
        cc = c[n-2-i] % modulo
        ans = (ans + (aa*cc%modulo))%modulo
    #print(a,b,c)
    print(ans)

            

def main():
    _ = input()
    a = list(map(int,input().split()))
    solve(a)


if __name__ == "__main__":
    main()