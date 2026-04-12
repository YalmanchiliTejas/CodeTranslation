from itertools import accumulate

N = int(input())
A = list([int(x) for x in input().split()])
check = list(accumulate(A))

MOD = 10**9 + 7

result = 0
for i in range(N):
    result += (A[i] * (check[N-1] - check[i]))
    result %= MOD

print(result)
