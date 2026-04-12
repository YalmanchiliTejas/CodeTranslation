N = int(input())
A = [int(num) for num in input().split()]

sumA = sum(A)
ans = 0
for i in range(len(A)):
    sumA = sumA - A[i]
    ans += A[i] * sumA


ans = ans % (10**9+7)
print(ans)