a, b, c, x, y = map(int, input().split())
ans = 0
min_ = min(x, y)
res = abs(x-y)
if a+b < 2*c:
    ans += min_*(a+b)
else:
    ans += min_*2*c
if x>y and res*a < res*2*c:
    ans += res*a
elif x<y and res*b < res*2*c:
    ans += res*b
else:
    ans += res*2*c
print(ans)