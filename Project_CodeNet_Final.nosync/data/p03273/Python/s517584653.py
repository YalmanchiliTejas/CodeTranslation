#!/usr/bin/env python3
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
h,w = map(int,input().split())
a = []
for i in range(h):
    a.append(input())
row = []
col = []
for i in range(h):
    if a[i] == "."*w: row.append(i)
for j in range(w):
    flag = 0
    for i in range(h):
        if a[i][j] != ".": flag = 1
    if flag == 0:
        col.append(j)
#print(row,col)
for i in range(h):
    flag = 0
    if i in row:
        #print("y")
        flag = 1
    if flag == 0:
        for j in range(w):
            if j not in col: print(a[i][j],end="")
        print("")



        