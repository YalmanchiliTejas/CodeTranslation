H, W = map(int, input().split())
a = []

for _ in range(H):
    sd = list(input())
    if '#' in sd:
        a.append(sd)

col = [False] * W

for i in range(W):
    if '#' in [row[i] for row in a]:
        col[i] = True

for i in range(len(a)):
    for j in range(W):
        if col[j]:
            print(a[i][j], end='')
    print()