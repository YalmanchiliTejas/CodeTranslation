#!/usr/bin/python3
# ABC058_C, ARC071_A
"""
怪文書 / Dubious Document
・入力される文字列にA-Zのどれが何回含まれるか確認する。(1~n, a~zの平面リスト)
・一番短い文字列を探して、それに含まれる文字だけ使う。
"""
from string import ascii_lowercase as abc

test = False


def answer():
    """
    答え
    例:l_count[0]は'a'の最少回数。
    """
    n = int(input())
    l_count = [51] * 26

    for _ in range(n):
        """
        各アルファベットの、含まれる最少回数のリストを作る。
        例：l_count[0] は 'a' の最少回数
        """
        temp_S = input()
        for i in range(26):
            """
            各アルファベットについて、含まれる回数が最少だった場合はリストに記録する。
            """
            temp_count = temp_S.count(abc[i])
            l_count[i] = min(l_count[i], temp_count)

    if test:
        print('l_count =', l_count)
    # ここまでで回数確認終わり

    # 答えの文字列の生成・出力
    temp_answer = ''
    for j in range(26):
        temp_answer += l_count[j] * abc[j]

    print(temp_answer)


def main():
    """
    main関数
    """
    answer()


if __name__ == '__main__':
    main()
