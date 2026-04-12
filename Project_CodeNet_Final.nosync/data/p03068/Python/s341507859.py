N = int(input())
S = list(input())
K = int(input())

x = S[K-1]
s = [i for i, t in enumerate(S) if t == x]

for i in range(N):
	if i not in s:
		S[i] = '*'
	else:
		pass

A = "".join(S)
print(A)