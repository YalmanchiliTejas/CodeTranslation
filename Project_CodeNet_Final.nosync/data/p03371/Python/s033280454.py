import math

a,b,c,x,y = map(int,input().split())

# cを全探索？
res = float('inf')
for i in range(max(x,y)*2+1):
    money = i * c
    if i/2<x:
        money += math.ceil(x-i/2) * a
    if i/2<y:
        money += math.ceil(y-i/2) * b
    res = min(res,money)

print(res)
