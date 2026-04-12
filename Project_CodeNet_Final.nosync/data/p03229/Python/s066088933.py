N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

A = sorted(A)

if N%2==0:
    l = A[:N//2]
    u = A[N//2:]
    ans = sum(u)*2-u[0] - (sum(l)*2-l[-1])
else:
    m = A[N//2]
    l = A[:N//2]
    u = A[N//2+1:]
    ans = max(sum(u)*2 - sum(l)*2 - m + l[-1], sum(u)*2 - sum(l)*2 + m - u[0])

print(ans)