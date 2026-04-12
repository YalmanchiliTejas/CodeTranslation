MOD = 1000000007
n = int(input())
A = [int(x) for x in input().split()]
result = 0
sumA = sum(A)
for a in A:
    sumA -= a
    result = (result + a * sumA) % MOD
print(result)
