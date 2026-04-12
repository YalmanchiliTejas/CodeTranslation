H, W = map(int, input().split())

a = []

# 必要な行だけ読み込む
for i in range(H):
    tmp = list(input())
    if "#" not in tmp:
        continue
    else:
        a.append(tmp)

# 転置して削って転置
a = list(zip(*a))
a = [x for x in a if "#" in x]
a = list(zip(*a))

for i in a:
    print("".join(i))