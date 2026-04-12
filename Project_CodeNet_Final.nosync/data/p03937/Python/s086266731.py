H, W = list(map(int, input().split()))
A = []

for i in range(H):
    s = input()
    A.append(list(s))

# for i in range(H):
#     print(A[i])

di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]

ans = True
for i in range(H):
    for j in range(W):
        # if (i == 0 and j == 0) or (i == H-1 and j == W-1):
        #     continue
        if A[i][j] == '#':
            ul = 0  # 上 or 左
            rd = 0  # 右 or 下
            for k in range(4):
                ni = i + di[k]
                nj = j + dj[k]
                if 0 <= ni < H and 0 <= nj < W:
                    if A[ni][nj] == '#':
                        if k == 0 or k == 1:
                            ul += 1
                        else:
                            rd += 1
            # print(i, j, ':', ul, rd)
            if i == 0 and j == 0:
                if not (ul == 0 and rd == 1):
                    ans = False
            elif i == H-1 and j == W-1:
                if not (ul == 1 and rd == 0):
                    ans = False
            else:
                if not (ul == 1 and rd == 1):
                    ans = False

if ans:
    print('Possible')
else:
    print('Impossible')
