n = int(input())
x = list(map(int, input().split()))

y = []

for i in range(n):
    y.append([x[i], i])

y.sort()

ans = [-1 for i in range(n)]

for i in range(n // 2):
    ans[y[i][1]] = y[n // 2][0]

for i in range(n // 2, n):
    ans[y[i][1]] = y[n // 2 - 1][0]

for i in range(n):
    print(ans[i])