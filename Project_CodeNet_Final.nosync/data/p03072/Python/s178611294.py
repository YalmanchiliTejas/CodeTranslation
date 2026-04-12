n = int(input())
h = list(map(int, input().split()))
ans = 1
for i in range(n):
  if i > 0:
    if all(h[i] >= j for j in h[:i]):
      ans += 1
print(ans)