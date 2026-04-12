#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

input = sys.stdin.readline

def main():
    N = int(input())
    H = list(map(int, input().split()))

    n = 1
    max_num = H[0]
    for i in range(1, N):
        if H[i] >= max_num:
            n += 1
            max_num = H[i]
    print(n)

main()
