N = int(raw_input())
S = str(raw_input())
K = int(raw_input())
l = []
for i in range(N):
	l.append(S[K-1] if S[i] == S[K-1] else '*')
print ''.join(l)