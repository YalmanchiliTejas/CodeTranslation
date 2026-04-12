import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))

S=sum(A)
ANS=0
mod=10**9+7
for i in range(N):
    ANS=ANS+(S-A[i])*A[i]
    ANS%=mod

print(ANS*pow(2,-1,mod)%mod)
