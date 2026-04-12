N = int(input())
A = list(map(int,input().split()))
B = []
p = sum(A)
for j in range(N-1):
    p -= A[j]
    B.append(p%(10**9+7))
count = 0
for i in range(N-1):
    count += (A[i]*B[i])%(10**9+7)
print(count%(10**9+7))