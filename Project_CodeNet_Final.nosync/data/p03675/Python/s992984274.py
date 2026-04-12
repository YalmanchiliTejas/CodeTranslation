# -*- coding: utf-8 -*-
def inpl(): return tuple(map(int, input().split()))

n = int(input())
A = inpl()

if n == 1:
    print(A[0])
else:
    if n % 2 == 0:
        print(" ".join(map(str, A[1::2][::-1] + A[::2])))
    else:
        print(" ".join(map(str, A[::2][::-1] + A[1::2])))