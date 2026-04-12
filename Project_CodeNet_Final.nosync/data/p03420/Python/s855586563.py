N,K=map(int,input().split())
count=0
for b in range(K+1,N+1):
	if K==0:
		count+=N
	else:
		x=N//b
		y=N%b
		count+=(x)*(b-K)
		if y>=K:
			count+=(y-(K-1))
print(count)