# -*- coding: utf-8 -*-
 
# t, s = map(str,input().split())

n = int(input())
str_a = input().split()

a = []
for i in range(len(str_a)):
    a.append(int(str_a[i]))

total = 0
c = 0
for i in range(n - 1):
    c += a[-i]
    total += c * a[-(i + 1)]

print(total % (1000000007))