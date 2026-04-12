X,Y,Z = map(int, input().split())

if X < Y+2*Z:
  ans = 0
else:
  _ = Z
  ans = 0
  while _ <= (X-Z):
    _ += Y
    _ += Z
    if _ <= X:
      ans += 1

print(ans)