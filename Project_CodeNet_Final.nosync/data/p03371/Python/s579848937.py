a, b, c, x, y = map(int, input().split())

ans = min(x, y) * min(a + b, c * 2)

if x > y:
  ans += (x - y) * min(a, c * 2)
elif x < y:
  ans += (y - x) * min(b, c * 2)

print(ans)