from sys import exit
import math
import collections
ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

n = ii()
s = input()
k = ii()

for i in range(n):
    if s[i] == s[k-1]:
        print(s[i],end="")
    else:
        print("*",end="")