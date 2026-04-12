# -*- coding: utf-8 -*-
# E - Sequence Decomposing
import sys 
from bisect import bisect_right

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
A = list(map(int,read().split()))
X = [-1]*N
for a in A:
    i = bisect_right(X,a-1)-1
    X[i] = a
print(N - X.count(-1)) 