# coding:UTF-8
import sys


def resultSur97(x):
    return x % (10 ** 9 + 7)


if __name__ == '__main__':
    # ------ 入力 ------#
    # 1行入力
    n = int(input())    # 数字
    aList = list(map(int, input().split()))     # スペース区切り連続数字

    # ------ 処理 ------#
    sum = 0
    for i in range(0, n):
        sum += aList[i]

    pro = 0
    for i in range(0, n):
        ai = aList[i]
        sum = sum - ai
        pro += sum * aList[i]

    out = resultSur97(pro)

    # ------ 出力 ------#
    print("{}".format(out))
    # if flg == 0:
    #     print("YES")
    # else:
    #     print("NO")
