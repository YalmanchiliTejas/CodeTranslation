N = int(input())
A = list(map(int, input().split()))

P = sum(A)**2
Q = 0
for i in range (0, N):
    Q+=(A[i])**2

print(((P-Q)//2)%(10**9+7))