N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7

sumA = sum(A)
S = 0

for x in range(N):
    sumA -= A[x]
    S = (S + A[x] * (sumA)) % mod

print(S)
