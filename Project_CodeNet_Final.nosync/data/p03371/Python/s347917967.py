a,b,c,x,y = map(int, input().split())
ans = 0
if x>y:
    z,d = x-y,a
else:
    z,d = y-x,b
if a+b > c*2:
    ans += min(x,y)*2*c
    if d > c*2:
        ans += z*2*c
    else:
        ans += z*d
else:
    ans += a*x + b*y

print(ans)