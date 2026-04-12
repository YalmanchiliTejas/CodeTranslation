N = int(input())
S = list("".join(input()))
K = int(input())

c = S[K-1]
for i in range(N):
	if S[i] != c:
		S[i] = "*"
print("".join(S))