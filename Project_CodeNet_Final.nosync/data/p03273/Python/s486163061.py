H,W=map(int,input().split())
a=[input() for _ in range(H)]

del_row="."*W

for i in range(len(a)):
    row=a.pop(0)
    if row!=del_row:
        a.append(row)

del_col="."*len(a)
del_list=[]
for w in range(W):
    string=""
    for h in range(len(a)):
        string+=str(a[h][w])
    if string==del_col:
        del_list.append(w)

ans_list=[]
for h in range(len(a)):
    string=""
    for w in range(W):
        if not w in del_list:
            string+=a[h][w]
    ans_list.append(string)

for i in ans_list:
    print(i)