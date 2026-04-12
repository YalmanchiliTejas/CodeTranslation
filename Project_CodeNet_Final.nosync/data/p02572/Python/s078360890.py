N = int(input())
A = list(map(int,input().split()))
B = sum(A)
new_A = A.reverse()
n = 0
for i in range(N-1):
    n += A[i]*(B-A[i])
    B = B-A[i]

print(n%(10**9+7))