# -*- coding: utf-8 -*-
"""
Created on Sat Apr 13 21:23:17 2019

@author: yuta
"""

N = int(input())
H = list(map(int,input().split()))

def main(n,h):
    count = 1
    max_h = h[0]
    for i in range(1,n):
        if h[i] >= max_h:
            max_h = h[i]
            count += 1
    print(count)
main(N,H)