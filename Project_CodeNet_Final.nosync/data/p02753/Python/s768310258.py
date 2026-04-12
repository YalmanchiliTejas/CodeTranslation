# -*- coding: utf-8 -*-


def get_input() -> str:
    """
    標準入力の取得.

    Returns:\n
        str: 標準入力
    """
    S = input()

    return S


def main(S: str) -> None:
    """
    求解処理.

    Args:
        S (str): 管理状況
    """
    result = str()
    if S == "AAA" or S == "BBB":
        result = "No"
    else:
        result = "Yes"

    # 結果出力
    print(result)


if __name__ == "__main__":
    S = get_input()
    main(S)
