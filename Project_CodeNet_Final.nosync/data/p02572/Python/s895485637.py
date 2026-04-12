N = int(input())
A = [int(v) for v in input().split()]
mod = 1000000007
cusum = [0]
for i in range(N):
    cusum.append(cusum[i] + A[i])

totalSum = 0
for i in range(N - 1):
    sum = (cusum[N] - cusum[i + 1]) % mod
    totalSum += sum * A[i]
    totalSum %= mod
print(totalSum)