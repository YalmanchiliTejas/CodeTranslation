n, x = [int(i) for i in input().split()]

# L0 =           1
# L1 =        0, 1, 2, 3, 3
# L2 =     0, 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7
# L3 =  0, 0, 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7, 8,
#          8, 8, 9,10,11,11,12,12,13,14,15,15,15,   15

# まずLnの長さ,Pの数を算出
length = [[0, 0] for i in range(n+1)]
length[0] = [1, 1]
for i in range(1, n+1):
    length[i][0] = length[i - 1][0] * 2 + 3
    length[i][1] = length[i - 1][1] * 2 + 1
    # print("L[{}]:{}".format(i, length[i]))


def search(i, x):
    pat = 0
    if i == 0:
        # print("i:{} x:{} pat:{}".format(i, x, 1))
        return 1
    # xが先頭の時
    elif x == 0:
        # print("i:{} x:{} pat:{}".format(i, x, 0))
        return 0
    # xが真ん中の時
    elif x == 1 + int((length[i][0] - 3) / 2):
        # print("i:{} x:{} pat:{}".format(i, x, length[i - 1][1] + 1))
        return length[i - 1][1] + 1
    # xが末尾の時
    elif x == length[i][0] - 1:
        # print("i:{} x:{} pat:{}".format(i, x, length[i][1]))
        return length[i][1]
    # xが中心より小さいとき
    elif x < 1 + int((length[i][0] - 3) / 2):
        pat = search(i - 1, x - 1)
    # xが中心より大きいとき
    elif x > 1 + int((length[i][0] - 3) / 2):
        pat = length[i - 1][1] + 1\
              + search(i - 1, x - 2 - int((length[i][0] - 3) / 2))
    # print("i:{} x:{} pat:{}".format(i, x, pat))
    return pat


print(search(n, x - 1))
