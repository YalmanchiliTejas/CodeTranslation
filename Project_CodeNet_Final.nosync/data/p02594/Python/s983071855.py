# -*- coding: utf-8 -*-
import sys 
sys.setrecursionlimit(10**6)
MOD = 10**9+7 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
if N >= 30:
    print('Yes')
else:
    print('No')