n = int(input())
A = list(map(int, input().split()))
total = 0
sum_A = sum(A)

for i in range(n-1):
    sum_A -= A[i]
    total += A[i] * sum_A

print(total%(10**9 + 7))