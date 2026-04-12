# -*- coding: utf-8
a = int(input())
b = list(map(int,input().split()))
s = 0
for i in range(a):
    s +=b[i]
tr = 0
for i in range(a):
    tr += b[i]**2
a2 = s**2-tr
a = a2//2
a %= 10**9+7
print(a)