N = int(input())
A = list(map(int, input().split()))
mod = 1000000007
S = 0
_sum = 0
for i in range(N):
    S += A[i]
    S %= mod
for i in range(N):
    S -= A[i]
    if S<0:
        S += mod
    _sum += A[i]*S
    _sum %= mod

print(_sum)