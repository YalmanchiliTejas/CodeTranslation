N = int(input())
S = str(input())
K = int(input())
Char = ''
for i in range(N):
	if S[i] != S[K-1]:
		Char += '*'
	else:
		Char += S[i]
print(Char)