H, W = map(int, input().split())
a = [input() for _ in range(H)]

kari = []
for i in a:
    if "#" not in i:
        H -= 1
        continue
    kari.append(i)

ans = ["" for _ in range(H)]
for i in range(W):
    for j in range(H):
        if kari[j][i] == "#":
            for k in range(H):
                ans[k] += kari[k][i]
            break

for i in ans:
    print(i)