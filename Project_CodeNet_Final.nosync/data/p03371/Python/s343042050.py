a,b,c,x,y = map(int,input().split())
l = 0
flg = x
if x > y:
    l += (x - y) * a
    flg = y
elif x < y:
    l += (y - x) * b
else:
    pass
l += flg * 2 * c
n = max(x,y) * 2 * c
m = x * a + y * b
print(min(l,n,m))