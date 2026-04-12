H, W = map(int, input().split())
row=[]
for i in range(H):
    row.append(input())
i=0
while(True):
    if('.'*W in row):
        row.remove('.'*W)
    else:
        break
columns=[]
for i in range(W):
    for j in range(len(row)):
        if(j==0):
            columns.append(row[j][i])
        else:
            columns[i]+=row[j][i]
while(True):
    if('.'*(len(row)) in columns):
        columns.remove('.'*len(row))
    else:
        break
row = []
for i in range(len(columns[0])):
    for j in range(len(columns)):
        if(j==0):
            row.append(columns[j][i])
        else:
            row[i]+=columns[j][i]
for i in range(len(row)):
    print(row[i])