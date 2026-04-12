N = int(input())
A = list(map(int,input().split()))

A_sum = sum(A)

value = 0
ans = 0

for i in range(N-1):
    A_sum -= A[i]
    value += A[i]*A_sum

ans = value % (1*10**9+7)

print(ans)