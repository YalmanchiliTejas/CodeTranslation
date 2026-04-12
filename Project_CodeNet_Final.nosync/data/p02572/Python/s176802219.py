N=int(input())
A=list(map(int,input().split()))
mod=10**9+7
S=0
M=0
for i in A:
    S+=i
for i in A:
    S-=i
    M+=(S*i)%mod
print(M%mod)