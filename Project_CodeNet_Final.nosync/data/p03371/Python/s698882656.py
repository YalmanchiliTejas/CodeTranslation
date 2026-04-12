a, b, ab, x, y = map(int, input().split())
if a+b <= 2*ab:
    print(a*x+b*y)
    exit()
ans = 0
if x >= y:
    if a >= 2*ab:
        ans = ab*2*x
    else:
        ans = ab*2*y + a*abs(x-y)
else:
    if b >= 2*ab:
        ans = ab*2*y
    else:
        ans = ab*2*x + b*abs(x-y)
print(ans)