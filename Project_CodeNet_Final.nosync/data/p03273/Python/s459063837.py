# -*- coding: utf-8 -*-
import pprint

H,W = list(map(int, input().rstrip().split()))
a_list=[list(input().rstrip()) for i in range(H)]
#-----

row_del_list=[]
for i,v in enumerate(a_list):
    if v.count(".") == W:
        row_del_list.append(i)

for i in row_del_list[::-1]:
    del a_list[i]
    H -= 1

       
column_del_list=[]
for j in range(W):
    cnt_white=0
    for i in range(H):
        if a_list[i][j] == ".":
            cnt_white += 1
    
    if cnt_white == H:
        column_del_list.append(j)
        
for j in column_del_list[::-1]:
    for i in range(H):
        del a_list[i][j]
        W -= 1


for row in a_list:
    print(*row,sep="")
