N=int(input())
L=list(map(int,input().split()))
tmp=0
ans=0
for i in range (N):
	if tmp<=L[i]:
		tmp=L[i]
		ans+=1
print(ans)