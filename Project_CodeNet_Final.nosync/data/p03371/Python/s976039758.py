a,b,c,x,y = map(int,input().split())
ans = 0
if 2*c <= a+b:
    m = min(x,y)
    x -= m
    y -= m
    ans += m*2*c
    ans += min(a,2*c)*x+min(b,2*c)*y
    print(ans)
else:
    print(a*x+b*y)