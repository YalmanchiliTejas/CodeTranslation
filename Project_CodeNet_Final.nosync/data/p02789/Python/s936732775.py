import sys
import os

#fname = "..\problems\problem1.txt"
#f = open(fname, 'r')
#sys.stdin = f

(N, M) = map(int, input().split())

if N == M:
    print('Yes')
else:
    print('No')
