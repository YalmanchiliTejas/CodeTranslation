h, w = map(int, input().split())
m = [[] for _ in range(h)]
x = [False] * h
y = [False] * w
for i in range(h):
    m[i] = list(input())
    if "#" in m[i]:
        x[i] = True
zm = list(zip(*m))
for i, j in enumerate(zm):
    if "#" in j:
        y[i] = True
M = []
for i, H in enumerate(x):
    for v, W in enumerate(y):
        if H and W:
            M.append(m[i][v])
    if M:
        print("".join(M))
    M = []
