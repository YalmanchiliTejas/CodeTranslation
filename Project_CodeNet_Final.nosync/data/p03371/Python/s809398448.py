a, b, c, x, y = map(int, input().split())
ans = 0

if a+b <= c*2:
    ans += min(x, y)*(a+b)
else:
    ans += min(x, y)*c*2

if x > y:
    if a <= c*2:
        ans += (x-y)*a
    else:
        ans += (x-y)*c*2
else:
    if b <= c*2:
        ans += (y-x)*b
    else:
        ans += (y-x)*c*2

print(ans)
