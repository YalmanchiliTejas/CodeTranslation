N = int(input())
S = input()
K = int(input())

s = S[K-1]
lett = ""

for i in range(N):
	if S[i] == s:
		lett += s
	else:
		lett +=("*")

print(lett)
