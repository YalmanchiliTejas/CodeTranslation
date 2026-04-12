res = 10**30
a,b,c,x,y = map(int,input().split())
for i in range(0,max(x,y)+1):
    # ABを2*iまい買う
    tmp = 2 * i * c
    xx,yy = x - i, y - i
    tmp += max(0,xx) * a
    tmp += max(0,yy) * b
    res = min(res, tmp)
print(res)
