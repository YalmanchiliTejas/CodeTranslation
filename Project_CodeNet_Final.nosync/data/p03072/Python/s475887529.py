N = int(input())
high = list(map(int, input().split()))
ans = 1
for i in range(1, N):
  boo = True
  for j in range(i):
    if high[j] > high[i]:
      boo = False
  if boo:
    ans += 1
print(ans)