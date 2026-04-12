N=int(input())

A=list(map(int,input().split()))

mod=10**9+7
summy=[]
a=0
for i in range(N):
    a += A[i]
    a %= mod
    summy.append(a)

ans=0
for i in range(N-1):
    ans += summy[N-2-i]*A[N-1-i]
    ans %= mod
print(ans)