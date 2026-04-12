n = int(input())
m=list(map(int,input().split()))
k=sum(m)
mod=10**9+7
s=0
for i in range(n):
    k-=m[i]
    s+=m[i]*k
    s%=mod
print(s)
    