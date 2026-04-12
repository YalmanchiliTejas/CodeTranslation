# import numpy as np
# import scipy as sp
# import sys
# input = sys.stdin.readline
# print(a,b,c,sep="") # 半角スペースなしで出力(abc)
# n=int(input())  #数値入力 「N」だけの入力のとき
# a,b=map(int, input().split())  #複数数値入力　「A B」みたいなスペース空いた入力のとき
# a=list(map(int, input().split()))  #リスト入力 「a1 a2 a3 ...」みたいな配列のような入力のとき
# a=[int(input()) for _ in range (n)]  #リスト入力  改行でa1 ... anのとき
# s=[list(map(str,list(input()))) for i in range(h)]  # 文字列の二次元配列入力
# s = [list(map(int, input().split())) for i in range(n)] # 数値の二次元配列入力
# a = b[:], a = [x[:] for x in b] # deepcopy
# chr(ord('a') + 1) # chrのインクリメント
# s.sort(key=lambda x: x[1], reverse=False) # 2番目の要素で昇順にソート（Trueなら降順）
#　

s = input()
if s == 'AAA' or s == 'BBB':
    print('No')
else:
    print('Yes')
