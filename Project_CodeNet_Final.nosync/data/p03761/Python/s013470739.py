from collections import Counter as c
N = int(input())

dup = {}
ans = dict(c(list(input())))
for _ in range(N-1):
	s = dict(c(list(input())))
	tmp = {}
	for ansk, ansv in ans.items():
		tmp[ansk] = min([ansv, s.get(ansk, 0)])
	ans = tmp

for c in sorted(list(ans.items()), key=lambda x: x[0]):
	print(c[0]*c[1], end= '')
print()