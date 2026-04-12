y,x=map(int,input().split())
lst=[]
for i in range(y):
    lst.append(input())
    
del_line=[]
del_row=[]
for i in range(y):
    cnt=0
    for j in range(x):
        if lst[i][j]==".":
            cnt+=1
    if cnt==x:
        del_line.append(i)
for i in range(x):
    cnt=0
    for j in range(y):
        if lst[j][i]==".":
            cnt+=1
    if cnt==y:
        del_row.append(i)

for i in range(y):
    if not i in del_line:
        pr=[]
        for j in range(x):
            if not j in del_row:
                pr.append(lst[i][j])
        print("".join(pr))