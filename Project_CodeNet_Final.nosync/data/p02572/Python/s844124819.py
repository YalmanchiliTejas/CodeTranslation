N = int(input())
A = list(map(int, input().split()))

tmp = 0
for i in range(N):
    tmp += A[i]*A[i]

ans = ((sum(A)*sum(A) - tmp)//2)%(10**9+7)
print(ans)