#coding:utf-8
a,b,c,x,y = map(int,input().split())
minv = a * x + b * y
c *= 2
big = max(x,y)
sml = min(x,y)
if a+b > c:
    minv = minv - (a+b) * sml + c * sml
if sml == x and b > c:
    minv = minv - (b-c) * (big - sml)
if sml == y and a > c:
    minv = minv - (a-c) * (big - sml)

print(minv)
    
