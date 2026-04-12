H, W = map(int, input().split())
hw = [list(input()) for i in range(H)]

# print(hw)
yoko_new = []
for x in range(H):
    # print(hw[x])
    yoko_check = True
    for y in range(W):
        if hw[x][y] == "#":
            yoko_check = False
    if not yoko_check:
        yoko_new.append(hw[x])

yoko_new_len = len(yoko_new)

tate_new = [["-1" * W] * yoko_new_len]

z = 0
while z < len(yoko_new[0]):
    # for z in range(W):
    tate_check = True
    for w in range(yoko_new_len):
        if yoko_new[w][z] == "#":
            tate_check = False
    if tate_check:
        for w in range(yoko_new_len):
            yoko_new[w].pop(z)
    else:
        z += 1
for v in yoko_new:
    print("".join(v))
