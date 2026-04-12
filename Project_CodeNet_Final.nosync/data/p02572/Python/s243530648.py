n=int(input())
lst=list(map(int,input().strip().split()))
s1=sum(lst)
num=s1*s1
denom=0 
mod=1000000007
for i in range(0,n):
        denom+=(lst[i]*lst[i])
print(((num-denom)//2)%mod)