a,b,c,x,y = map(int,input().split())

ans = 0
if a+b <= 2*c:
    ans = a*x+b*y
else:
    if x>y:
        ans += 2*c*y
        l = x-y
        r = a
    else:
        ans += 2*c*x
        l = y-x
        r = b
    if 2*c < r:
        ans += 2*c*l
    else:
        ans += l*r

print(ans)