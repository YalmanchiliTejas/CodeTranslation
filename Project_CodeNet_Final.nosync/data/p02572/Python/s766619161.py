n=int(input())
L=list(map(int,input().split()))
s=0
t=0
p=10**9+7
x=5*10**8+4
for i in range(0,n):
	s=(s+L[i])%p
	t=(t+L[i]*L[i])%p

ans=x*(pow(s,2,p)-t)

print(ans%p)