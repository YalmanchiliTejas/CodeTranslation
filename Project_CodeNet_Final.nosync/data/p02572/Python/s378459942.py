n = int(input())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

res = 0
tmp = 0
for i in range(1, n):
    tmp += A[i - 1]
    res += A[i] * tmp
    res %= MOD

print(res)
