N = int(input())
A = list(map(int,input().split()))
sumA = sum(A)
c = 0

for i in range(N-1):
    c+= A[i]* (sumA-A[i])
    sumA-= A[i]
print(c%(10**9+7))