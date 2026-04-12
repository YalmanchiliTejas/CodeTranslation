N, T, E = map(int, input().split())
x = list(map(int, input().split()))

a = []
for i in range(N):
    for j in range(T-E, T+E+1):
        if j % x[i] == 0:
            a.append(i+1)

if len(a) == 0:
    print(-1)
else:
    print(a[0])
