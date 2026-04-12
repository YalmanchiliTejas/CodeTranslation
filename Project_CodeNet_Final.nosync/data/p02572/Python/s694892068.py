N = int(input())

A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

max_edge = sum(A)

tmp = 0

for num in A:
    tmp += num ** 2

print((max_edge ** 2 - tmp) // 2 % MOD)