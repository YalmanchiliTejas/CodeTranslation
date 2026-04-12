N=int(input())
A=list(map(int,input().split()))
mod=10**9+7

inv_A=A[::-1]

b = [0]*N
b[0]=inv_A[0]
for i in range(1,N):
    b[i] = (b[i-1]+inv_A[i])%mod
inv_b = b[::-1]

print( sum(A[i]*inv_b[i+1]%mod for i in range(0,N-1))%mod )