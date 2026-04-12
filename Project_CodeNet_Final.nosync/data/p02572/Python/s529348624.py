N = int(input())
A = input().split()

sum = 0
SUM = 0
for i in range(N-1, 0, -1):
    sum += int(A[i])
    SUM += int(A[i-1])*sum
ans = SUM%1000000007
print(ans)
