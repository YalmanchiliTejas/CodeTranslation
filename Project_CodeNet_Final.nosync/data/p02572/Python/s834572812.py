N = int(input())
A = [int(s) for s in input().split()]

mod_number = 10**9 + 7
sum_A = sum(A)
total = 0
for i in range(0, N - 1):
    sum_A = sum_A - A[i]
    total += A[i] * sum_A

ans = total % mod_number

print(ans)