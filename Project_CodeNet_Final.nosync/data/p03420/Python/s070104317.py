N,K=[int(x) for x in input().split()]
counter=0
for b in range(max(1,K),N+1):
	tobeadded=(N//b)*(b-K) + max(0,N%b+1-K)
	counter+=tobeadded
if K==0:
	counter-=N
print(counter)