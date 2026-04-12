H, W = map(int, input().split())
a = []
b = []
c = []
i = 0
j = 0
k = 0
while i < H:
    moji = input()
    if "#" in moji:
        a.append([m for m in moji])
    i += 1
while j < W:
    ls = [row[j] for row in a]
    if "#" in ls:
        b.append(ls)
    j += 1
while k < len(b[0]):
    ls = [row[k] for row in b]
    c.append(ls)
    k += 1
for row in c:
    print("".join(row))
