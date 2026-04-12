a, b, c, x, y = map(int,input().split())

value = a+b
values = c*2

ans = 0

if value <= values:
    ans += a*x + b*y
    print(ans)
    exit()

if x>=y:
    ans += c*y*2
    
    if a <= c*2:
        ans += a*(x-y)
    else:
        ans += c*2*(x-y)

else:
    ans += c*x*2
    
    if b <= c*2:
        ans += b*(y-x)
    else:
        ans += c*2*(y-x)
        
print(ans)