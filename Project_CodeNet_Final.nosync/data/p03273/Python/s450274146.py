H, W = list(map(int, input().split()))
hw = [list(input()) for _ in range(H)]

index = 0
row = []
while True:
    # 縦
    if hw[index][0] == '.':
        clearable = 0
        for i in range(W):
            if hw[index][i] == '.':
                clearable += 1
        if clearable != W:
            row.append(hw[index][:])
    else:
        row.append(hw[index][:])

    index += 1
    if index == H:
        break

# 転置して横と似たような処理で縦も処理する
rowt = [list(x) for x in list(zip(*row))]

index = 0
cols = []
while True:
    # 横
    if rowt[index][0] == '.':
        clearable = 0
        for i in range(len(rowt[index])):
            if rowt[index][i] == '.':
                clearable += 1
        if clearable != len(rowt[index]):
            cols.append(rowt[index][:])
    else:
        cols.append(rowt[index][:])

    index += 1
    if index == len(rowt):
        break

# 転置してるので元に戻す
ans = [list(x) for x in list(zip(*cols))]

for i in range(len(ans)):
    print(''.join(ans[i]))
