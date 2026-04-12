a, b, c, x, y = map(int, input().split())
c *= 2
ans = min(a+b, c) * min(x, y)
if x>y:
    ans += (x-y)*min(a, c)
else:
    ans += (y-x)*min(b, c)
print(ans)