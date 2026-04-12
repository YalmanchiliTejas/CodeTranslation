a,b,c,x,y = map(int,input().split())
l = 0
p = x

if x > y:
    l += (x - y) * a
    p = y
elif x < y:
    l += (y - x) * b
    p = x
else:
    pass
l += p * 2 * c
n = max(x,y) * 2 * c
m = x * a + y * b
print(min(l,n,m))