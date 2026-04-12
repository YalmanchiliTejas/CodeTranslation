a,b,c,x,y = map(int,input().split())
ans = 0
if a > c*2:
    a = c*2
if b > c*2:
    b = c*2
if a + b >= c*2:
    ans += min(x,y)*c*2
    if x > y:
        ans += (x-y)*a
    else:
        ans += (y-x)*b
else:
    ans = a*x + b*y
print(ans)