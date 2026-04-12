N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7

S = sum(A)**2

T = 0
for a in A:
    T+=a**2

S -= T
S //= 2
S%=mod
print(S)