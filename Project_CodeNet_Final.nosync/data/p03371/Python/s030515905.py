# -*- coding: utf-8 -*-
import sys


def get_input() -> tuple:
    """
    標準入力を取得する.

    Returns:\n
        tuple: 標準入力
    """
    A, B, C, X, Y = list(map(int, input().split()))

    return A, B, C, X, Y


def main(A: int, B: int, C: int, X: int, Y: int) -> None:
    """
    メイン処理.

    Args:\n
        A (int): Aピザの値段
        B (int): Bピザの値段
        C (int): ABピザの値段
        X (int): Aピザの必要枚数
        Y (int): Bピザの必要枚数
    """
    # 求解処理
    ans = sys.maxsize
    max_c = 2 * max(X, Y)
    for c in range(0, max_c + 1, 2):
        a = max(X - c // 2, 0)
        b = max(Y - c // 2, 0)
        price = a * A + b * B + c * C
        ans = min(ans, price)

    # 結果出力
    print(ans)


if __name__ == "__main__":
    # 標準入力を取得
    A, B, C, X, Y = get_input()

    # メイン処理
    main(A, B, C, X, Y)
