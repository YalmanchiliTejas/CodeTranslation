H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
yoko = [True if "#" in a[i] else False for i in range(H)]
b = [list(x) for x in zip(*a)]
tate = [True if "#" in b[i] else False for i in range(W)]
for j in range(H):
    for i in range(W):
        if yoko[j] and tate[i]:
            print(a[j][i], end="")
    if yoko[j]:
        print()
