N = int(input())
S = input()
K = int(input())

diff = set(S) - set(S[K - 1])
#print(diff)
for d in diff:
	S = S.replace(d, "*")
print(S)