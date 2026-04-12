from collections import Counter
N = int(input())
S = [Counter(input()) for i in range(N)]

merged = S[0]
for s in S:
  merged &= s

ans = ""

for (key, value) in merged.items():
  ans += key * value

print("".join(sorted(ans)))