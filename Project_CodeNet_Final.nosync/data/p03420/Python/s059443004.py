N,K=map(int, input().split())
if K==0:
	print(N*N)
else:
	count = 0
	for b in range(K+1, N+1):
		chk = (N//b)*max(0, b-K)+max(N%b-K+1, 0)
		count += chk
	print(count)
