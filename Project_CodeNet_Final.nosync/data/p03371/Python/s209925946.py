a,b,c,x,y = map(int,input().split())
tmpans = max(x,y)*2*c
ans = 0
if a+b > 2*c:
    tmp = min(x,y)
    ans += tmp *(2*c)
    x -= tmp
    y -= tmp
    ans += x*a + y*b
else:
    ans += x*a + y*b
print(min(ans,tmpans))