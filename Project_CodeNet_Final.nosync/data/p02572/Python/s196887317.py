N = int(input())

A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

edge = sum(A)

diagonal_sum = 0
for num in A:
    diagonal_sum += num ** 2

s = (edge*edge - diagonal_sum) // 2

print(s % MOD)