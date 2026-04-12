n = int(input())
A = [int(x) for x in input().split()]

mod = 10**9 + 7

cusum = [0]
for i in range(n):
    cusum.append(cusum[i]+A[i])

totalSum = 0
for i in range(n-1):
    sum = (cusum[n] - cusum[i + 1]) % mod
    totalSum += sum * A[i]
    totalSum %= mod

print(totalSum)
