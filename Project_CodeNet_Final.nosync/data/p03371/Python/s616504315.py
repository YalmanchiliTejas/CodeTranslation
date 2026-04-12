a,b,c,x,y = map(int,input().split())
res = 10**10
for i in range(0,2*max(x,y)+1,2):
    if x-i//2<0:
        na=0
    else:
        na=x-i//2
    if y-i//2<0:
        nb=0
    else:
        nb=y-i//2
    cost = a*na+b*nb+c*i
    if cost < res:
        res = cost
    else:
        break
print(res)