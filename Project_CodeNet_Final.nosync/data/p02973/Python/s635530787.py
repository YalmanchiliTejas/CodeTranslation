#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import bisect as bi


def solve():
    N = int(input())
    A = []
    heads = []
    for _ in range(N):
        A.append(int(input()))
    a = A.pop()
    bi.insort(heads, a)
    while A:
        a = A.pop()
        if a < heads[-1]:
            j = bi.bisect(heads, a)
            del heads[j]
        bi.insort(heads, a)
    return len(heads)
  

def main():
    print(solve())


if __name__ == "__main__":
    main()
