# -*- coding: utf-8 -*-

n = int(input())
a_list = list(map(int, input().split()))

s = 0
summation = 0
for i in a_list:
  s += i

for i in a_list:
  s -= i
  summation += i * (s)

print(summation % (10 ** 9 + 7))