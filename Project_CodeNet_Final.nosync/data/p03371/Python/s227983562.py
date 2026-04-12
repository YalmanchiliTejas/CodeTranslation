a,b,c,x,y = map(int, input().split())

if a+b >= 2*c:
    if x <= y:
        ans = 2*c*x
        y -= x
        if 2*c <= b:
            ans += 2*c*y
        else:
            ans += b*y
    else:
        ans = 2*c*y
        x -= y
        if 2*c <= a:
            ans += 2*c*x
        else:
            ans += a*x
else:
    ans = a*x + b*y
    
print(ans)