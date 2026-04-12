
import sys
input = sys.stdin.readline
N, X, M = map(int,input().split())
A = [0 for _ in range(M+1)]
A[1] = X
S = [0 if i == 0 else X for i in range(M+1)]
first = [-1 for i in range(M+1)]
if X <= M:
	first[X] = 1

n = 1
a = X
l,r = -1, -1
while True:
	if n == N:
		break
	a2 = (a*a) % M
	if a2 == 0:
		print(S[n])
		exit()
	if first[a2] > 0:
		l = first[a2]
		r = n
		break
	first[a2] = n + 1
	A[n+1] = a2
	S[n+1] = S[n] + a2
	a = a2
	n += 1

if n == N:
	print(S[N])
	exit()
t = r - l + 1
loop = (N-l+1) // t
rest = (N-l+1) % t
print(S[l-1] + loop * (S[r] - S[l-1]) + S[l + rest - 1] - S[l-1])