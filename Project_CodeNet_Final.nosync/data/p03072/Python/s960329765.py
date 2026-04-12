n = int(input())
A = list(map(int ,input().split()))
ans = 0
maxA = 0
for i in range(n):
    if(A[i] >= maxA):
        maxA = A[i]
        ans += 1
print(ans)