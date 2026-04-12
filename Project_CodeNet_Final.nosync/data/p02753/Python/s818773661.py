# abc158_a.py
# https://atcoder.jp/contests/abc158/tasks/abc158_a

# A - Station and Bus /
# 実行時間制限: 2 sec / メモリ制限: 1024 MB
# 配点 : 100点

# 問題文
# AtCoder 市には 3つの駅があり、1,2,3の番号がつけられています。
# これらの駅は、それぞれ鉄道会社A, Bのいずれかが管理しています。
# 管理状況は長さ 3の文字列 S で表され、駅 i は Siが A のとき鉄道会社 A が、B のとき鉄道会社 B が管理しています。
# 鉄道会社 A が管理している駅と、鉄道会社 B が管理している駅の間には、交通の便のためにバスを運行することになりました。
# 実際にバスが運行することになる駅の組み合わせが存在するかどうかを判定してください。

# 制約
#     Sは A または B から成る
#     |S|=3

# 入力
# 入力は以下の形式で標準入力から与えられる。
# S

# 出力
# バスが運行することになる駅の組み合わせが存在する場合は Yes を、存在しない場合は No を出力せよ。

# 入力例 1
# ABA

# 出力例 1
# Yes

# 駅 1,3は鉄道会社 A が、駅 2は鉄道会社 B が管理しています。
# 駅 1,2間と駅 2,3間でバスが運行するので、Yes を出力してください。

# 入力例 2
# BBA

# 出力例 2
# Yes

# 駅 1,2は鉄道会社 B が、駅 3は鉄道会社 A が管理しています。
# 駅 1,3間と駅 2,3間でバスが運行するので、Yes を出力してください。

# 入力例 3
# BBB

# 出力例 3
# No

# 駅は全て鉄道会社 B が管理しているので、バスは運行しません。よって No を出力してください。


global FLAG_LOG
FLAG_LOG = False


def log(value):
    # FLAG_LOG = True
    # FLAG_LOG = False
    if FLAG_LOG:
        print(str(value))


def calculation(lines):
    S = lines[0]
    # N = int(lines[0])
    # N, M = list(map(int, lines[0].split()))
    # values = list(map(int, lines[1].split()))
    # values = list(map(int, lines[2].split()))
    # values = list()
    # for i in range(N):
    #     values.append(int(lines[i]))
    # valueses = list()
    # for i in range(N):
    #     valueses.append(list(map(int, lines[i+1].split())))

    if S == 'AAA' or S == 'BBB':
        result = 'No'
    else:
        result = 'Yes'

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
        lines_input = ['ABA']
        lines_export = ['Yes']
    if pattern == 2:
        lines_input = ['BBA']
        lines_export = ['Yes']
    if pattern == 3:
        lines_input = ['BBB']
        lines_export = ['No']
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
