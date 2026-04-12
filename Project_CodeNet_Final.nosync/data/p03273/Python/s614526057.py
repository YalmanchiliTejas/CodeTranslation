#!/usr/bin/env python3

h,w = map(int,input().split())
a = []
dlrow = []
dlcol = []

efrow = list(range(h))
efcol = list(range(w))

# input
for i in range(h):
    a.append(input())

# row
for i in range(h):
    flg = True
    for j in range(w):
        if a[i][j] == '#':
            flg = False
    # delete this row
    if flg == True:
        dlrow.append(i)
        efrow.remove(i)

#print("dlrow =",dlrow)
#print("efrow =",efrow)

# column
for j in range(w):
    flg = True
    for i in range(h):
        if a[i][j] == '#':
            flg = False
    # delete this column
    if flg == True:
        dlcol.append(j)
        efcol.remove(j)

#print("dlcol =",dlcol)
#print("efcol =",efcol)

# print
for i in efrow:
    s = []
    s2 = []
    for j in efcol:
      s.append(a[i][j])
      s2 = "".join(s)
    print(s2) 
