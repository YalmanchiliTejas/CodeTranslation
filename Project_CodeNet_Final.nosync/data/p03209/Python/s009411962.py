N, X = map(int, input().split())

C = [0]*(N+1)
D = [0]*(N+1)
C[0] = D[0] = 1
for i in range(1, N+1):
    C[i] = 2*C[i-1] + 1
    D[i] = 2*D[i-1] + 3

ans = 0
for i in range(N-1, -1, -1):
    if X == 0:
        break
    X -= 1
    if X < D[i]:
        continue
    ans += C[i]
    X -= D[i]
    if X == 0:
        break
    X -= 1; ans += 1
    if X < D[i]:
        continue
    X -= D[i]
    ans += C[i]
    if X == 0:
        break
    X -= 1
print(ans)