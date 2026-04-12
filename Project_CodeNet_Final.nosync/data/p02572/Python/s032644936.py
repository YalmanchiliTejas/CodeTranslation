N = int(input())
A = list(map(int, input().split()))

sumA = sum(A)

ans = 0

for i in range(len(A)):
    sumA -= A[i]
    ans += sumA * A[i]

print(ans % 1000000007) 