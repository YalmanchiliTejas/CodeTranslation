n=int(input())
L=list(map(int,input().split()))
cnt=0
for i in range(n):
	cnt+=L[i]**2

ans=(sum(L)**2-cnt)//2
mod=pow(10,9)+7

print(ans%mod)