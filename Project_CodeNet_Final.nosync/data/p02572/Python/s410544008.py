# -*- coding: utf-8 -*-

def get_input() -> tuple:
    """
    標準入力を取得する.

    Returns:\n
        tuple: 標準入力
    """
    # 標準入力を取得
    N = int(input())
    A = list(map(int, input().split()))

    return N, A


def main(N: int, A: list) -> None:
    """
    メイン処理.

    Args:\n
        N (int): 整数(2 <= N <= 2 * 10**5)
        A (list): 整数(0 <= A_i <= 10**9)
    """
    # 求解処理
    mod = 10**9 + 7
    ans = 0
    sum_A_j = sum(A)
    for i in range(N):
        A_i = A[i]
        sum_A_j -= A_i
        ans += A_i * sum_A_j
        ans %= mod

    # 結果出力
    print(ans)


if __name__ == "__main__":
    # 標準入力を取得
    N, A = get_input()

    # メイン処理
    main(N, A)
