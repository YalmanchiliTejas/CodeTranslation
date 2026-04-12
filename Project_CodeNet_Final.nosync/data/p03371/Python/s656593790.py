a,b,c,x,y = map(int,input().split())

ans = 0
if min(x,y)==x:
    ans += x*min(a+b,2*c)
    y -= x
    x = 0
else:
    ans += y*min(a+b,2*c)
    x -= y
    y = 0
    
if x == 0:
    ans += y*min(b, 2*c)
else:
    ans += x*min(a, 2*c)

print(ans)