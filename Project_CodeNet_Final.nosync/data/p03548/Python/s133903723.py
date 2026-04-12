X, Y, Z = map(int,input().split())
ans=0
for i in range(100005):
  if X - i * Y - (i + 1) * Z >= 0:
    ans = i
  else:
    break
print(ans)