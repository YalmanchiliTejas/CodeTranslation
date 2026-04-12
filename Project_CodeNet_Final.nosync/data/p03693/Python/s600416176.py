#!/usr/bin/python

a = [int(i) for i in input().split()]

n = 100 * a[0] + 10 * a[1] + a[2]

if n % 4 == 0:
  print("YES")
else:
  print("NO")