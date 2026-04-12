# input
H, W = map(int, input().split())
a = [list(input()) for h in range(H)]

for w in range(W):
    g = [a[h][w] for h in range(H)]
    if set(g) == {"."}:
        for h in range(H):
            a[h][w] = ""

for h in range(H):
    g = a[h]
    if set(g) != {"."} and set(g) != {"", "."}:
        print("".join(g))