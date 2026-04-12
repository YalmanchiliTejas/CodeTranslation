h,w = map(int,input().split())

aa = [input() for _ in range(h)]
aa_rm=[]
target_row=[]
for row,a in enumerate(aa):
    if a.count('.') < w:
        target_row.append(row)

target_col=[]
for iw in range(w):
    col=[]
    for ih in range(h):
        col.append(aa[ih][iw])
    # print(col)
    if col.count('.') < h:
        target_col.append(iw)

ans =[]
for row in target_row:
    s=""
    for col in target_col:
        s+=aa[row][col]
    ans.append(s)
for a in ans:
    print(a)
