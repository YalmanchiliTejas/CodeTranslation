n = int(input())

A = list(map(int, input().split()))

sum_A = sum(A)

total = 0

for i in range(n):
    sum_A = sum_A - A[i]
    total += (sum_A * A[i]) % (10**9 + 7)
    total %= (10**9 + 7)
print(total)