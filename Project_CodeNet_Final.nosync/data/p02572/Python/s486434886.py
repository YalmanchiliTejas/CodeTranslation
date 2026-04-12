N = int(input())
A = list(map(int,input().split()))
sumA = sum(A)
SUM = 0
for i in range(1,N):
    sumA -= A[i]
    SUM += A[i]*sumA
print(SUM % (10**9+7))