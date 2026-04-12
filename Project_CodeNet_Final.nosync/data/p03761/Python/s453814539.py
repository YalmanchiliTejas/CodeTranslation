import bisect,copy,heapq,string
from collections import *
from math import *
from itertools import *
import sys
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

n = INT()
s = [input() for i in range(n)]
a = [[0]*26 for i in range(n)]

for i in range(n):
        for j in range(len(s[i])):
                a[i][ord(s[i][j])-ord('a')] += 1

ans = ""
for j in range(26):
        ans += chr(ord('a')+j)*min(a[i][j] for i in range(n))

print(ans)