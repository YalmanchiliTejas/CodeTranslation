N = int(input())
S = [input() for _ in range(N)]

m = set(S[0])
for s in S[1:]:
	m &= set(s)

c = {}
for a in m:
	min_c = 2 ** 31 - 1
	for s in S:
		min_c = min(min_c, s.count(a))
	c[a] = min_c

for a in sorted(m):
	print(a * c[a], end="")
print()
