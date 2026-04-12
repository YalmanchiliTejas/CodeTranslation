n= int(input())
a = list(map(int, input().split()))
s=0
ans=0

mod = 1000000007

s= sum(a)

for i in a:
    s-=i
    ans+=i*s%mod
    ans%=mod
print(ans)

