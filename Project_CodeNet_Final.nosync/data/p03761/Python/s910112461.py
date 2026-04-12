def cnt(s, b):
	ans = []
	for i in s:
		if i in b:
			ans.append(i)
	return ans

def resolve():
	n = int(input())
	h = []
	for i in range(n):
		h.append(input())
	ans = h[0]
	for i in range(1, n):
		sec = list(set(ans) & set(h[i]))
		tmp = ""
		for j in sec:
			tmp += j*min(ans.count(j), h[i].count(j))
		ans = tmp

	print("".join(sorted(ans)))
resolve()