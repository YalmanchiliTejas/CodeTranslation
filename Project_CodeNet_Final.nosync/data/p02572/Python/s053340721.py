l=int(input())
k=list(map(int,input().split()))
s=0
mod=10**9+7
o=sum(k)
p=o**2

s=0
for i in k:
    s=(s+i**2)
    
print((p-s)//2%mod)