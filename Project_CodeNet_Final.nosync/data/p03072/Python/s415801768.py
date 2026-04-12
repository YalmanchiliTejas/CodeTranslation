n = int(input())
lih = list(map(int,input().split()))

ans = 0
for i in range(n):
  if i == 0:
    ans += 1
  else:
    if max(lih[0:i]) <= lih[i]:
      ans += 1
print(ans)