a, b, c, x, y = map(int, input().split())

ans = 0

if c*2 < a+b:
    ans += min(x, y) * c * 2
    if x > y:
        ans += min(a, 2*c) * abs(x-y)
    elif x < y:
        ans += min(b, 2*c) * abs(x-y)
else:
    ans += a * x + b * y

print(ans)