N = int(input())
A = [int(a) for a in input().split()]
ans = 1
ma = A[0]
for i in range(1, N):
    if A[i] >= ma:
        ans += 1
        ma = A[i]
print(ans)