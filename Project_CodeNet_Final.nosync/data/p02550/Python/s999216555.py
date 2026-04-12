# -*- coding: utf-8 -*-

def get_input() -> tuple:
    """
    標準入力を取得する.

    Returns:\n
        tuple: 標準入力
    """
    # 標準入力を取得
    N, X, M = list(map(int, input().split()))

    return N, X, M


def f(x: int, m: int) -> int:
    """
    xをmで割った余りを返す.

    Args:\n
        x (int): 整数
        m (int): 整数

    Returns:\n
        int: xをmで割った余り
    """
    return x % m


def main(N: int, X: int, M: int) -> None:
    """
    メイン処理.

    Args:\n
        N (int): 整数(1 <= N <= 10^{10})
        X (int): 整数(0 <= X <= M <= 10^5)
        M (int): 整数(0 <= X <= M <= 10^5)
    """
    # 求解処理
    A = [X]
    s = {X}
    i = 0
    while True:
        A_next = f(A[-1]**2, M)
        if A_next in s:
            i = A.index(A_next)
            break
        else:
            A.append(A_next)
            s.add(A_next)

    loop_length = len(A) - i
    loop_cnt = (N - i) // loop_length
    loop_res = (N - i) % loop_length
    ans = sum(A[:i]) + loop_cnt * sum(A[i:]) + sum(A[i: i + loop_res])

    # 結果出力
    print(ans)


if __name__ == "__main__":
    # 標準入力を取得
    N, X, M = get_input()

    # メイン処理
    main(N, X, M)
