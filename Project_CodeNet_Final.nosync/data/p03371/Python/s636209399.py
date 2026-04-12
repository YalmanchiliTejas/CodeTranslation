a, b, c, x, y = map(int, input().split())
ans = 0
mi = min(x, y)

if a+b > c*2:
    ans = min(c*max(x, y)*2, c*mi*2 + a*(x-mi) + b*(y-mi))
else:
    ans = a*x + b*y

print(ans)