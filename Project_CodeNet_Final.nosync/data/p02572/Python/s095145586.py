N=int(input())
A=list(map(int, input().split()))
ans=0
SM=sum(A)
for i in range(N-1):
	SM-=A[N-1-i]
	ans+=A[N-i-1]*SM
	ans=ans%(10**9+7)
					
print(ans)