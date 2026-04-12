N=int(input())
A=list(map(int,input().split()))
ans=1
t=A[0]
for i in range(1,N):
	if t<=A[i]:
		ans+=1
		t=A[i]
print(ans)