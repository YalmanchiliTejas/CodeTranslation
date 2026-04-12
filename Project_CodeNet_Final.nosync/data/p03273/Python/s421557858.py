#coding:utf-8
import numpy as np
h,w = map(int,input().split())
mat = []
for i in range(h):
    mat.append(list(input()))
mat = np.array(mat)
#mat=np.array([['.','#'],['#','#']])#test
isDot = mat == '.'
y = list(np.where(np.mean(isDot,axis=0)!=1)[0])
x = list(np.where(np.mean(isDot,axis=1)!=1)[0])
output = mat[np.ix_(x,y)]
for line in output:
    print("".join(line))
