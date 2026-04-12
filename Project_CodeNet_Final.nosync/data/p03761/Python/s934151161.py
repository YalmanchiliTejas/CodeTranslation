from collections import defaultdict
d = defaultdict(int)

N = int(input())
S = [input() for n in range(N)]

for s in S[0]:
  d[s] += 1

for index, s in enumerate(S):
  if index == 0:
    continue
  
  k = defaultdict(int)

  for i in s:
    k[i] += 1

  for t in k:
    if d[t] > k[t]:
      d[t] = k[t]

  for t in d:
    if k[t] == 0:
      d[t] = 0

ans = ""
for i in d:
  if d[i] == 0:
    continue

  ans += i * d[i]

ans = sorted(ans)
ans = "".join(ans)
print(ans)