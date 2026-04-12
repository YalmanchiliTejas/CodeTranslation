from collections import Counter
N = int(input())
S = [input() for i in range(N)]

C = []

for s in S:
  cnt = Counter()
  for cha in s:
    cnt[cha] += 1
  C.append(cnt)

merged = C[0]
for c in C:
  cnt = Counter()
  for (key1, value1) in merged.items():
    for (key2, value2) in c.items():
      if key1 == key2:
        cnt[key1] = min(value1, value2)
  merged = cnt

ans = ""

for (key, value) in merged.items():
  ans += key * value

print("".join(sorted(ans)))