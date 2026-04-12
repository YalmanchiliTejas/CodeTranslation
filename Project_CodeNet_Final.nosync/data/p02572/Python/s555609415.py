N=int(input())
An=list(map(int,input().split()))
mod=10**9+7
s=sum(An)
S=0
num = 0
for i in range(N):
    num += An[i]
    S += (An[i]*(s-num))
print(S%mod)