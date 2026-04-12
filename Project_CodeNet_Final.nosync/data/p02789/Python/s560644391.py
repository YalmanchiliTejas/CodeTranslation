# abc152_a.py
# https://atcoder.jp/contests/abc152/tasks/abc152_a

# A - AC or WA /
# 実行時間制限: 2 sec / メモリ制限: 1024 MB
# 配点 : 100点

# 問題文
# 高橋君は、プログラミングコンテスト AXC001 に参加しており、問題 A にコードを提出しました。
# この問題には N個のテストケースがあり、すべてのテストケースに正解した場合のみ提出は AC となります。
# 高橋君の提出は、N 個のテストケースのうち M個のテストケースに正解しました。
# 高橋君の提出が AC となるか判定してください。

# 制約
#     1≤N≤100
#     0≤M≤N
#     入力はすべて整数である。

# 入力
# 入力は以下の形式で標準入力から与えられる。
# N M

# 出力
# 高橋君の提出が AC となる場合は Yes, そうでない場合は No と出力せよ。

# 入力例 1
# 3 3

# 出力例 1
# Yes

# 3つのテストケースすべてに正解したので、AC となります。

# 入力例 2
# 3 2

# 出力例 2
# No

# 3つのテストケース中 2つしか正解できなかったので、AC となりません。

# 入力例 3
# 1 1

# 出力例 3
# Yes


global FLAG_LOG
FLAG_LOG = False


def log(value):
    # FLAG_LOG = True
    # FLAG_LOG = False
    if FLAG_LOG:
        print(str(value))


def calculation(lines):
    # S = lines[0]
    # N = int(lines[0])
    N, M = list(map(int, lines[0].split()))
    # values = list(map(int, lines[1].split()))
    # values = list(map(int, lines[2].split()))
    # values = list()
    # for i in range(N):
    #     values.append(int(lines[i]))
    # valueses = list()
    # for i in range(N):
    #     valueses.append(list(map(int, lines[i+1].split())))

    if N == M:
        result = 'Yes'
    else:
        result = 'No'

    return [result]


# 引数を取得
def get_input_lines(lines_count):
    lines = list()
    for _ in range(lines_count):
        lines.append(input())
    return lines


# テストデータ
def get_testdata(pattern):
    if pattern == 1:
        lines_input = ['3 3']
        lines_export = ['Yes']
    if pattern == 2:
        lines_input = ['3 2']
        lines_export = ['No']
    if pattern == 3:
        lines_input = ['1 1']
        lines_export = ['Yes']
    return lines_input, lines_export


# 動作モード判別
def get_mode():
    import sys
    args = sys.argv
    global FLAG_LOG
    if len(args) == 1:
        mode = 0
        FLAG_LOG = False
    else:
        mode = int(args[1])
        FLAG_LOG = True
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
