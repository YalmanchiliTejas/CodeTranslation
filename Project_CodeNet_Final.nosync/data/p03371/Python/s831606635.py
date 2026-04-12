a,b,c,x,y = map(int,input().split())
c *= 2
ans = 0
z = min(x,y)
if x >= y:
    w = x-z
    v = a
else:
    w = y-z
    v = b

ans += min(a+b,c)*z

ans += min(v,c)*w

print(ans)