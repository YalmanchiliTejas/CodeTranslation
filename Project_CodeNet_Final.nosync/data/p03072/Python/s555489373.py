N = int(input())
H = list(map(int, input().split()))
count = 0
ans = 0
for i in range(1, N):
  for j in range(i):
    if H[j] <= H[i]:
      count += 1
  if count == i:
    ans += 1
  count = 0
print(ans+1)