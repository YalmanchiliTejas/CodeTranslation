"""
input(): 入力を文字列として1行取ってくる
"文字列".split(): 文字列をパースする（空白などで分割する）
    例："2 3 4 5"　をsplitしたら、[2, 3, 4, 5] に分割する
map(型, list): list の中身をそれぞれ指定した型で変数に入れる
"""
N, M = map(int, input().split())

if N == M:
    print("Yes")
else:
    print("No")
