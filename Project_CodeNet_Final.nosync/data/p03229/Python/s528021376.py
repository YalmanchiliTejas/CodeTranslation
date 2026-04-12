# https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c

import math

n = int(input())
num = [int(input()) for _ in range(n)]
num.sort()


def dif():
    ans = 0
    for i in range(1, n):
        ans += abs(b[i] - b[i - 1])
    return ans


b = [0]*n
# print(num)
if (n % 2 == 0):
    for i in range(n // 2):
        b[i * 2 + 1] = num[i]
        b[i * 2] = num[i + n // 2]
    # print(b)
    print(dif())
    # 大小大小…と並べていけば最適
    # 先頭・末尾以外は、大同士、小同士を入れ替えても差の絶対値に変化がない→中央値より大きい数値を小さい方から、中央値より小さい数値を小さい方から使っていけばいい
    # 偶数の時は中央値は真ん中の左側として、末尾に配置
    # 先頭の値は中央値より大きい値の内一番小さい値
else:
    # 奇数の時は中央値はもちろん真ん中の値
    # 先頭におくか末尾におくかでパターンが分かれる
    for i in range(n // 2):
        b[i * 2 + 1] = num[i]
        b[i*2] = num[i+n//2+1]
    b[n - 1] = num[n // 2]
    temp = dif()
    # print(b)
    for i in range(n // 2):
        b[i * 2 + 2] = num[i]
        b[i*2+1] = num[i+n//2+1]
    b[0] = num[n // 2]
    # print(b)
    print(max(dif(), temp))