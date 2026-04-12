# abc107_b.py
# https://atcoder.jp/contests/abc107/tasks/abc107_b

# B - Grid Compression /
# 実行時間制限: 2 sec / メモリ制限: 1024 MB
# 配点 : 200点

# 問題文
# 縦 H行、横 W 列のマス目があります。 上から i 行目、左から j 列目のマスを (i,j) と表します。 
# 各マスは白または黒です。 マス目の配色は、H 行 W 列の行列 (ai,j) によって与えられます。 
# ai,j が . ならばマス (i,j) は白であり、ai,j が # ならばマス (i,j)は黒です。
# すぬけ君はこのマス目を圧縮しようとしています。 そのために、白いマスのみからなる行または列が存在する間、次の操作を繰り返し行います。

#     操作: 白いマスのみからなる行または列をひとつ任意に選び、その行または列を取り除いて空白を詰める。

# 各操作でどの行または列を選ぶかによらず、最終的なマス目は一意に定まることが示せます。 最終的なマス目を求めてください。

# 制約
#     1≤H,W≤100
#     ai,jは . または # である。
#     マス目全体で少なくともひとつは黒いマスが存在する。

# 入力
# 入力は以下の形式で標準入力から与えられる。
# H W
# a1,1...a1,W
# :
# aH,1...aH,W

# 出力
# 最終的なマス目を、入力と同様のフォーマットで出力せよ。 ただし、行数および列数は省くこと。 詳しくはサンプルを参照せよ。

# 入力例 1
# 4 4
# ##.#
# ....
# ##.#
# .#.#

# 出力例 1
# ###
# ###
# .##

# 元のマス目における第 2行および第 3列がそれぞれ取り除かれます。

# 入力例 2
# 3 3
# #..
# .#.
# ..#

# 出力例 2
# #..
# .#.
# ..#

# 白いマスのみからなる行または列が存在しないので、操作は行われません。

# 入力例 3
# 4 5
# .....
# .....
# ..#..
# .....

# 出力例 3
# #

# 入力例 4
# 7 6
# ......
# ....#.
# .#....
# ..#...
# ..#...
# ......
# .#..#.

# 出力例 4
# ..#
# #..
# .#.
# .#.
# #.#


def calculation(lines):
    N, W = list(map(int, lines[0].split()))
    masus = list()
    for i in range(N):
        line = lines[i+1]
        if line != '.'*W:
            masus.append(line)
    for w in range(W):
        flag = True
        for masu in masus:
            if masu[w] == '#':
                flag = False
        if flag:
            for i in range(len(masus)):
                masus[i] = masus[i][:w] + ' ' + masus[i][w+1:]
    for i in range(len(masus)):
        masus[i] = masus[i].replace(' ', '')
    return masus


# 引数を取得
def get_input_lines():
    line = input()
    H, W = list(map(int, line.split()))
    lines = list()
    lines.append(line)
    for _ in range(H):
        lines.append(input())
    return lines


# テストデータ
def get_testdata(pattern):
    if pattern == 1:
        lines_input = ['4 4', '##.#', '....', '##.#', '.#.#']
        lines_export = ['###', '###', '.##']
    if pattern == 2:
        lines_input = ['3 3', '#..', '.#.', '..#']
        lines_export = ['#..', '.#.', '..#']
    if pattern == 3:
        lines_input = ['4 5', '.....', '.....', '..#..', '.....']
        lines_export = ['#']
    if pattern == 4:
        lines_input = ['7 6', '......', '....#.', '.#....', '..#...', '..#...', '......', '.#..#.']
        lines_export = ['..#', '#..', '.#.', '.#.', '#.#']
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
    mode = get_mode()
    if mode == 0:
        lines_input = get_input_lines()
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


# 起動処理
if __name__ == '__main__':
    main()
