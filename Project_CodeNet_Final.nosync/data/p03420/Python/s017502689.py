N,K = map(int, input().split())

answer = 0

if K == 0:
	answer = N*N
else:
	for b in range(K+1, N+1):
		add = N//b * max(b-K, 0) + max(N%b+1-K, 0)
		answer += add

print(answer)
