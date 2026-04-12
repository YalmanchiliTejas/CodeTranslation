n = int(input())
h = list(map(int, input().split()))

ans = 1
for i in range(1, n):
  if all(h[i] >= h[j] for j in range(i)):
    ans += 1
  else:
    continue
print(ans)