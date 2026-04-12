r, g, b = map(int, input().split())
if (g * 10 + b) % 4 == 0:
  ans = "YES"
else:
  ans = "NO"
print(ans)