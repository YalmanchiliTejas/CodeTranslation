n=int(input())
arr=list(map(int,input().split()))
mod=pow(10,9)+7
tempa=sum(arr)%mod
tempa=(tempa*tempa)%mod
tempb=0
for i in arr:
	tempb=(tempb+(i*i))%mod
ans=(tempa-tempb)%mod
ans=ans*pow(2,mod-2,mod)
print(ans%mod)