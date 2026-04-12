n = int(input())
A = list(map(int,input().split()))
ans = 1
for i in range(1,n):
    if max(A[:i]) <= A[i]:
        ans += 1
print(ans)
