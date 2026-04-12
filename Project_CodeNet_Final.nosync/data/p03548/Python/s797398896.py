X, Y, Z = map(int, input().split())
b = Y + 2 * Z
ans = 1
while True:
  b += Y + Z
  if b > X:
    break
  else:
    ans += 1
print(ans)