N, X, M = map(int, input().split())
A = [[0] * (10**5+1) for _ in range(34)]
B = [[0] * (10**5+1) for _ in range(34)]

for i in range(10**5+1):
    A[0][i] = B[0][i] = i**2 % M
for i in range(33):
    for j in range(10**5+1):
        A[i+1][j] = A[i][A[i][j]]
        B[i+1][j] += B[i][j] + B[i][A[i][j]]
now = X
ans = X
i = 0
N -= 1
while N > 0:
    if N & 1:
        ans += B[i][now] 
        now = A[i][now]
    N >>= 1
    i += 1
print(ans)