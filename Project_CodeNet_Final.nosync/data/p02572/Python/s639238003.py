n = int(input())
A = list(map(int, input().split()))

sumA = sum(A)
sumB = 0
sumC = sumA

for i in range(n):
    sumC = sumC- A[i]
    sumB += A[i] * sumC

print(sumB % (10**9 + 7))
