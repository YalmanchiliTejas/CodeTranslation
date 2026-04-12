x, y, z = map(int, input().split())
ans = x // (y + z)
if x % (y + z) < z:
  ans -= 1
print(ans)