# coding: utf-8
r,g,b = map(int,raw_input().split())
r=r*100
g=g*10
b=b
score = r+g+b
if score%4==0:
  print 'YES'
else:
  print 'NO'