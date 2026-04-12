N = int(input())
X = list(map(int, input().split()))
P = []
for i in range(N):
    P.append((X[i], i))

P = sorted(P)
med = [P[N // 2 - 1][0], P[N // 2][0]]
ans = [0] * N
for i in range(N):
    if P[i][0] <= med[0]:
        ans[P[i][1]] = P[N // 2][0]
    else:
        ans[P[i][1]] = P[N // 2 - 1][0]

for i in ans:
    print(i)

