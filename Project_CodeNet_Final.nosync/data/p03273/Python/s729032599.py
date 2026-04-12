import numpy as np
h,w=map(int,input().split())
"""
入力はスペースなしだった
文字列としてリストの行にぶち込む必要あり
icon=list()
for i in range(h):
    icon.append(list(input().split()))

"""
icon=[''] * h
for i in range(h):
    icon[i]=input()


row=[False]*h
col=[False]*w

for i in range(h):
    for j in range(w):
        if icon[i][j]=='#':
            row[i]=True
            col[j]=True

for  i in range(h):
    if row[i]==True:
        for j in range(w):
            if col[j]==True:
                print(icon[i][j],end='')
        print()  