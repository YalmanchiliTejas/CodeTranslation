# coding: utf-8

r,g,b=map(int,input().split())

tmp=r*100+g*10+b

if tmp%4==0:
    print("YES")
else:
    print("NO")