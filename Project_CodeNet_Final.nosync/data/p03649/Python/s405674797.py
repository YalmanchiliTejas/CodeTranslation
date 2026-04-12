n=int(input())
a=list(map(int,input().split()))
cnt=0
ans=0
while True:
	for i in range(n):
		r=a[i]//n
		a[i]%=n
		a[i]-=r
		cnt+=r
	ans+=cnt
	if cnt==0:
		break
	for i in range(n):
		a[i]+=cnt
	cnt=0
print(ans)