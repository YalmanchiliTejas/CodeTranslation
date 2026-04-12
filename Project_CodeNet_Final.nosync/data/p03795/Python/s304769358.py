# -*- coding: utf-8 -*-
import sys
# sys.setrecursionlimit(10000)


def main():
    # 入力処理
    N = int(input())

    # アルゴリズム本体
    x = 800 * N
    y = 200 * int(N / 15)

    # 出力
    print(x-y)


if __name__ == '__main__':
    main()
