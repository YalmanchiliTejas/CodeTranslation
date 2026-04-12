a,b,c,x,y = map(int, input().split())

ans = 0

if x<y:
    xy = x
    y -= x
    if b < 2*c:
        ans += b*y
    else:
        ans += 2*c*y

else:
    xy = y
    x -= y
    if a < 2*c:
        ans += a*x
    else:
        ans += 2*c*x

if a+b<2*c:
    ans += xy*(a+b)
else:
    ans += xy*(2*c)

print (ans)
