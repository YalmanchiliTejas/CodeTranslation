n = int(input())
S = input()
k = int(input())
c = S[k-1]
res = ""
for s in S:
	if s == c:
		res += c
	else:
		res += '*'
print(res)
