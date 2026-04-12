N = int(input())
A = [int(x) for x in input().split()]

sums = [0] * N
sums[0] = A[0]
for i in range(N - 1):
    sums[i + 1] = sums[i] + A[i + 1]  # sums[i] stores the sum of A0~Ai

sum = 0
for i in range(N):
    sum += A[i] * (sums[N-1] - sums[i])

print(sum % 1000000007)