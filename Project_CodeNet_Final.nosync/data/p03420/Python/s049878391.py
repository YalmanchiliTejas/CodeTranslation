N,K = map(int,input().split(" "))

ans = 0
for b in range(K+1,N+1):
	#for rem in range(K,b):
	# ans += (N - rem) // b

	k = ((N - K) // b)
	num = min(((N - K) % b) + 1,b-K)
	other = (b - K) - num

	ans += ((b - K) * (k + 1) - other)
	

if K == 0:
	print(ans - N)
else:
	print(ans)