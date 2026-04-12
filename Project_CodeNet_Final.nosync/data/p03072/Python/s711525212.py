# abc124_b.py
# https://atcoder.jp/contests/abc124/tasks/abc124_b

# B - Great Ocean View /
# 実行時間制限: 2 sec / メモリ制限: 1024 MB
# 配点 : 200点

# 問題文
# 東西に N個の山が連なっており、西の果てには広大な海が広がっています。
# 各山頂には旅館があり、あなたは海を眺められる旅館を選ぶことにしました。
# 西から i番目の山の高さは Hiです。
# 西から 1番目の山頂にある旅館からは必ず海を眺めることができます。
# 西から i(i=2,3,...,N) 番目の山頂にある旅館については、H1≤Hi, H2≤Hi, ..., 
# かつ Hi−1≤Hiのとき、その旅館から海を眺めることができます。
# これら N個の旅館のうち、海を眺められる旅館はいくつあるでしょうか。

# 制約
#     入力は全て整数である。
#     1≤N≤20
#     1≤Hi≤100

# 入力
# 入力は以下の形式で標準入力から与えられる。
# N
# H1 H2 ... HN

# 出力
# 海を眺められる旅館の数を出力せよ。

# 入力例 1
# 4
# 6 5 6 8

# 出力例 1
# 3

# 西から 1,3,4番目の旅館から海を眺めることができます。

# 入力例 2
# 5
# 4 5 3 5 4

# 出力例 2
# 3

# 入力例 3
# 5
# 9 5 6 8 4

# 出力例 3
# 1


def log(line):
    if False:
        print(line)


def calculation(lines):
    # line = lines[0]
    N = int(lines[0])
    values = list(map(int, lines[1].split()))
    # values = list(map(int, lines[1].split()))
    # values = list(map(int, lines[1].split()))
    # values = list()
    # for i in range(6):
    #     values.append(int(lines[i]))
    # valueses = list()
    # for i in range(Q):
    #     valueses.append(list(map(int, lines[i+1].split())))

    result = 0

    for i in range(N):
        if values[i] >= max(values[:i+1]):
            result += 1

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
        lines_input = ['4', '6 5 6 8']
        lines_export = [3]
    if pattern == 2:
        lines_input = ['5', ' 4 5 3 5 4']
        lines_export = [3]
    if pattern == 3:
        lines_input = ['5', '9 5 6 8 4']
        lines_export = [1]
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
        lines_input = get_input_lines(2)
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
