# -*- coding: utf-8 -*-

def get_input() -> int:
    """
    標準入力を取得する.

    Returns:\n
        int: 室温
    """
    X = int(input())

    return X


def main(X: int) -> None:
    """
    メイン処理.

    Args:\n
        X (int): 室温（-40 <= X <= 40, 整数）
    """
    # 求解処理
    ans = str()
    if X >= 30:
        ans = "Yes"
    else:
        ans = "No"

    # 結果出力
    print(ans)


if __name__ == "__main__":
    # 標準入力を取得
    X = get_input()

    # メイン処理
    main(X)
