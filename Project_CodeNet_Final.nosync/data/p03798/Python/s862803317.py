import sys
sys.setrecursionlimit(100000000)
def input():
    return sys.stdin.readline()[:-1]
from bisect import *
from collections import *
from heapq import *
from math import *

n = int(input())
s = input()
s = [0 if t == 'o' else 1 for t in s]
x = [None]*n
for a, b in [(0,0), (0,1), (1,0), (1,1)]:
    x[0], x[1] = a, b
    flag = 1
    for i in range(2, n):
        x[i] = 1^x[i-2] if x[i-1]^s[i-1] else x[i-2]
    for i in range(n-1):
        if (x[i]^s[i])^(x[i-1] != x[i+1]):
            flag = 0
            break
    if flag and ((x[n-1]^s[n-1])^(x[n-2] != x[0])) == 0:
        x = ['S' if t == 0 else 'W' for t in x]
        print(*x, sep='')
        exit()
print(-1)
