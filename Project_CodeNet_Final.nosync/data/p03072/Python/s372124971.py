n = int(input())
h = list(map(int, input().split()))
ans = 0
for i in range(len(h)):
  count = 0
  for j in range(i):
    if h[j]<=h[i]:
      count += 1
  if count == i:
    ans += 1
print(ans)