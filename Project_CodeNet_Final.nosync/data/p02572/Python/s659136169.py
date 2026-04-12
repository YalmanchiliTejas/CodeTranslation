mod=10**9+7
n=int(input())
l=list(map(int,input().split()))
s=[]
for i in range(n):
    if i==0:
        s.append(l[i])
    else:
        s.append(s[-1]+l[i])
ans=0
for i in range(n):
    ans=(ans+l[i]*(s[-1]-s[i]))%mod
print(ans%mod)