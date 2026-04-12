N,M,K = list(map(int,input().split()))

mod = 10**9 + 7

A = ((N**2)*(N-1))//2 - (N*(2*N-1)*(N-1))//6
A = A*(M**2)
A %= mod
B = 1
for i in range(1,K-1):
    B *= N*M-1-i
    B %= mod
    B *= pow(i,mod-2,mod)
    B %= mod
ans1 = A*B

N,M = M,N
A = ((N**2)*(N-1))//2 - (N*(2*N-1)*(N-1))//6
A = A*(M**2)
A %= mod
B = 1
for i in range(1,K-1):
    B *= N*M-1-i
    B %= mod
    B *= pow(i,mod-2,mod)
    B %= mod
ans2 = A*B

print((ans1+ans2)%mod)