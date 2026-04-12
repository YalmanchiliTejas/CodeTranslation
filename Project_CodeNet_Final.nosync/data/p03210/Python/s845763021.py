# abc114_a.py
# https://atcoder.jp/contests/abc114/tasks/abc114_a

# A - 753 /
# 実行時間制限: 2 sec / メモリ制限: 1024 MB
# 配点 : 100点

# 問題文
# 七五三とは、7歳、5 歳そして 3歳の子どもの成長を祝うとある国の行事です。
# いま、高橋くんは X歳です。今回の七五三で、高橋くんの成長は祝われるでしょうか？

# 制約
#     1≤X≤9
#     Xは整数である。

# 入力
# 入力は以下の形式で標準入力から与えられる。
# X


# 出力
# 高橋くんの成長が祝われるなら YES, 祝われないなら NO と出力せよ。

# 入力例 1
# 5

# 出力例 1
# YES

# 5歳の子どもの成長は祝われます。

# 入力例 2
# 6

# 出力例 2
# NO

# また来年。


def calculation(lines):
    X = int(lines[0])
    # N, M = list(map(int, lines[0].split()))
    if X in [3, 5, 7]:
        return ['YES']
    else:
        return ['NO']


# 引数を取得
def get_input_lines(lines_count):
    lines = list()
    for _ in range(lines_count):
        lines.append(input())
    return lines


# テストデータ
def get_testdata(pattern):
    if pattern == 1:
        lines_input = ['5']
        lines_export = ['YES']
    if pattern == 2:
        lines_input = ['6']
        lines_export = ['NO']
    return lines_input, lines_export


# 動作モード判別
def get_mode():
    import sys
    args = sys.argv
    if len(args) == 1:
        mode = 0
    else:
        mode = int(args[1])
    return mode


# 主処理
def main():
    import time
    started = time.time()
    mode = get_mode()
    if mode == 0:
        lines_input = get_input_lines(1)
    else:
        lines_input, lines_export = get_testdata(mode)

    lines_result = calculation(lines_input)

    for line_result in lines_result:
        print(line_result)

    # if mode > 0:
    #     print(f'lines_input=[{lines_input}]')
    #     print(f'lines_export=[{lines_export}]')
    #     print(f'lines_result=[{lines_result}]')
    #     if lines_result == lines_export:
    #         print('OK')
    #     else:
    #         print('NG')
    # finished = time.time()
    # duration = finished - started
    # print(f'duration=[{duration}]')


# 起動処理
if __name__ == '__main__':
    main()
