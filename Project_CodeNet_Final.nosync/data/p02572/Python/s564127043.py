N = int(input())
A = list(map(int,input().split()))

mod = 10**9 + 7

S = 0
T = 0

for i in range(len(A)):
    S += A[i]
    T += A[i]**2
    S %= mod
    T %= mod

print(((S**2-T)*pow(2,mod-2,mod))%mod)