N = int(input())

A = list(map(int, input().split()))

total = 0
for i in range(N):
    total += A[i]

sum = 0
for i in range(N-1):
    total -= A[i]
    sum += (A[i] * total) % 1000000007
print(sum % 1000000007)
