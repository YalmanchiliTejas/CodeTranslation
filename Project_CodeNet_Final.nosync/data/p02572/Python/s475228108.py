N = int(input())
A = list(map(int, input().split()))
mod = (10 ** 9) + 7
answer = 0
sum_A = sum(A)

for i in range(N):
    sum_A -= A[i]
    answer += A[i] * sum_A % mod
print(answer % mod)