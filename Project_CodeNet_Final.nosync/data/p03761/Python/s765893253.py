import collections as c
N = int(input())

keys = []
vals = []
for _ in range(N):
	S = c.Counter(input())
	keys.append(list(S.keys()))
	vals.append(list(S.values()))

ans = [0 for _ in range(26)]
for i in range(97,123):
	tmp = float("inf")
	for j in range(N):
		if chr(i) in keys[j]:
			tmp = min(tmp, vals[j][keys[j].index(chr(i))])
		else:
			tmp = -1
			break
	if tmp == -1:
		continue
	else:
		ans[i-97] = tmp

for i in range(26):
	print(chr(i+97)*ans[i], end="")
print()
