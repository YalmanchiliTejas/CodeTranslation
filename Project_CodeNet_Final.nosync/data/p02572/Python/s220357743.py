MOD = 10 ** 9 + 7

n = int(input())
A = list(map(int, input().split()))

s =  sum(A)
result = 0
for i in range(n):
    s -= A[i]
    result += A[i] * s
    result %= MOD

print(result)
