from collections import Counter

n = int(input())
S = [input() for _ in range(n)]
ans = ''
count = Counter(S[0])

for s in S:
	count &= Counter(s)
for a, n in sorted(count.items()):
	ans += a * n
print(ans)