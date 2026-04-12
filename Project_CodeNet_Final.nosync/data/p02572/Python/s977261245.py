# C　Sum of product of pairs
N = int(input())
A = list(map(int, input().split()))
t = sum(A)
x = t - A[0]
mod = 10 ** 9 + 7
ct = 0
for i in range(N-1):
    ct += A[i] * x
    x = x - A[i+1]

print((ct % mod))
int((ct % mod))
