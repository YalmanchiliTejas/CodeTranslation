N = int(input())
A = list(map(int, input().split()))

sum1 = sum(A)
sum2 = 0
for i in range(N-1):
    sum1 -= A[i]
    sum2 += A[i] * sum1
print(sum2 % (10 ** 9 + 7))