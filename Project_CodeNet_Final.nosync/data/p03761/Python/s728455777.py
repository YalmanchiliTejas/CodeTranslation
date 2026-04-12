n = int(input())
S = [list(input()) for i in range(n)]
X = "qwertyuiopasdfghjklzxcvbnm"
ans = []
for i in range(26):
	res = []
	for s in S:
		res.append(s.count(X[i]))
	for j in range(min(res)):
		ans.append(X[i])
ans.sort()
print("".join(ans))