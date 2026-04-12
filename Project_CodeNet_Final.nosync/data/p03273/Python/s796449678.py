n,m=map(int,input().split())
arr=[]
for i in range(n):
    s1=str(input())
    arr.append(s1)
row1=[]
col1=[]
for i in range(n):
    if(arr[i].count('.')<m):
        row1.append(i)
for j in range(m):
    for i in range(n):
        if(arr[i][j]!='.'):
            col1.append(j)
            break
for i in row1:
    s1=""
    for j in col1:
        s1+=arr[i][j]
    print(s1)