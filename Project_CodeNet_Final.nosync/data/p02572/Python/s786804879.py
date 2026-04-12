N=int(input())
A=list(map(int,input().split()))

mod=1000000007
S=0
sl=0

for i in range (N):
    sl+=A[i]
    sl%=mod
    
for j in range(N):
    sl-=A[j]
    if sl<0:
        sl+=mod
    S+=A[j]*sl
    S=S%mod

print(S)
