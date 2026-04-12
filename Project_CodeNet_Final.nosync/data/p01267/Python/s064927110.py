#! /usr/bin/python
# -*- coding: utf-8 -*-

(N, A, B, C, X) = map(int, raw_input().split())
while N != 0:
    Y = map(int, raw_input().split())
    F = -1
    p = 0
    for i in range(10001):
        if X == Y[p]:
            p += 1
            if p >= N:
                F = i
                break
        X = (A*X+B)%C

    print F
    (N, A, B, C, X) = map(int, raw_input().split())