a,b,c,x,y = map(int, input().split())

if 2*c < a+b:
    if x < y:
        ans = 2*c * x + min(2*c, b) * (y - x)
    else:
        ans = 2*c * y + min(2*c, a) * (x - y)
else:
    ans = a * x + b * y
print(ans)