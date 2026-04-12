#import numpy as np
h,w=map(int,input().split())
a=[list(input()) for i in range(h)]

rowIndex=[False]*h
colIndex=[False]*w

for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            rowIndex[i]=True
            colIndex[j]=True
    
for i in range(h):
    if rowIndex[i]:
        for j in range(w):
            if colIndex[j]:
                print(a[i][j],end='')
        print()