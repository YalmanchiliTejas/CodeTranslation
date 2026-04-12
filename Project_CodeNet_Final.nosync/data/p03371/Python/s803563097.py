import sys


def main():
    A, B, C, X, Y = map(int, sys.stdin.readline().rstrip().split())

    K = max(X, Y) * 2  # 全部ハーフピザで注文する場合

    cost = 5000 * 10**6
    for i in range(K + 1):

        # 不足枚数
        rest_X = max(X - i // 2, 0)
        rest_Y = max(Y - i // 2, 0)

        # 金額を計算し、最小値を求める
        cost = min(rest_X * A + rest_Y * B + i * C, cost)

    print(cost)


main()
