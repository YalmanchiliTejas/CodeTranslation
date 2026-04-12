N=int(input())
L=list(map(int,input().split()))
count=0
while(1):
	K=max(L)
	if max(L)<N:
		print(count)
		exit()
	else:
		tmp=0
		#print(max(L))
		M=K//N
		count+=M
		for i in range(N):
			if L[i]==K and tmp==0:
				#print(i)
				tmp=1
				L[i]=K%N
			else:
				L[i]+=M
		#print(L)