N,K = map(int,input().split())
ans = 0
for b in range(K+1, N+1):
	# a=K, K+b, K+2b, ...
	n = N // b
	r = N % b
	c = b - K
	ans += n * c
	if r >= K:
		if K > 0:
			ans += r - K + 1
		else:
			ans += r - K
print(ans)