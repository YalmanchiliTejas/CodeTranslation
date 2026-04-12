N = int(input())
A = list(map(int,input().split()))

s = 0
mod = 10**9 + 7
for i in range(N-1):
    n = A[i] * A[i+1]
    n = n % mod
    s += n
    s %= mod
    A[i+1] += A[i]
print(s)