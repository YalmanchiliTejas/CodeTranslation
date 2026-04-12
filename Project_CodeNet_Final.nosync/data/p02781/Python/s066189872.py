import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N = input()
    length = len(N)
    K = int(input())

    # 左からi桁目まで見て，N以下が確定していて，0でない数字がk個ある数字の個数
    dp_1 = [[0] * (10) for _ in range(length)]

    # 左からi桁目まで見て，N以下が確定していなくて，0でない数字がk個ある数字の個数
    dp_2 = [[0] * (10) for _ in range(length)]

    dp_1[0][0] = 1
    dp_1[0][1] = int(N[0]) - 1

    dp_2[0][1] = 1

    for i in range(1, length):
        # 小さいのが確定しているものに対して，0以外のものを追加
        for k in range(1, K + 2):
            dp_1[i][k] += dp_1[i - 1][k - 1] * 9

        # 小さいものが確定しているものに対して，0を追加
        for k in range(0, K + 2):
            dp_1[i][k] += dp_1[i - 1][k]

        # 大小がわからないものから，小さいのが確定する
        if N[i] == "0":
            for k in range(K + 2):
                dp_2[i][k] += dp_2[i - 1][k]
        else:
            # 0を追加する
            for k in range(K + 2):
                dp_1[i][k] += dp_2[i - 1][k]

            # その他の数字を追加
            for k in range(1, K + 2):
                dp_1[i][k] += dp_2[i - 1][k - 1] * (int(N[i]) - 1)

            # 依然として大小関係がわからない
            for k in range(1, K + 2):
                dp_2[i][k] += dp_2[i - 1][k - 1]

    ans = dp_1[-1][K] + dp_2[-1][K]
    print(ans)


if __name__ == "__main__":
    main()
