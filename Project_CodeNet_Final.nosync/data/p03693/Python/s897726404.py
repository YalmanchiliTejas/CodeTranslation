#coding: utf-8
input = input().split()
r = input[0]
g = input[1]
b = input[2]
x = int(r+g+b)
if x%4==0:
  print('YES')
else:
  print('NO')
