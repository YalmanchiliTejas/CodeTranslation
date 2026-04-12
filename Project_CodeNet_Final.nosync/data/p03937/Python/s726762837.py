#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 数値の読み込み

h,w = list(map(int,input().split()))
m = [list(input()) for i in range(h)]

x=0
for i in range(h):
    for j in range(x,w):
        #print(i,j,m[i][j])
        if m[i][j] == '#':
            #print("find")
            m[i][j]='.'
            x=j
        else:
            break
result="Possible"
for i in range(h):
    for j in range(w):
        if m[i][j] == '#':
            result="Impossible"

print(result)