N=int(input())
number=list(map(int,input().split()))
MOD = 10**9+7
sum=sum(number)
s=sum%MOD
ans=0
for i in number:
    s-=i
    s%=MOD
    ans+=s*i
    ans%=MOD
print(ans)