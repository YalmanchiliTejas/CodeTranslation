#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    N,A,B,C,X = map(int,input().split(" "))
    if N == 0 and A == 0 and B == 0 and C == 0 and X == 0:
        break
    Y = list(map(int,input().split(" ")))
    pointer = 0

    for i in range(10001):
        X = (A*X+B)%C if i != 0 else X
        if X == Y[pointer]:
            pointer += 1
            if pointer == len(Y):
                break

    if pointer != len(Y):
        print(-1)
    else:
        print(i)