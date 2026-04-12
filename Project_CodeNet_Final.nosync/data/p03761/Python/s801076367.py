from collections import Counter

N = int(input())
counter = [Counter(input()) for _ in range(N)]

c = counter[0]
for i in range(1, N):
  for k, v in c.items():
    c[k] = min(counter[i][k], c[k])

c = sorted(c.items())
ans = ""
for k, v in c:
  ans += k * v
print(ans)