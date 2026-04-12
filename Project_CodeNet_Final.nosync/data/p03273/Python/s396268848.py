h,w=map(int,input().split())
a=[]
for i in range(h):
    a.append(list(input()))

row=[]
for i in range(h):
     flag=False
     for j in range(w):
         if(a[i][j]=='#'):
             flag=True
             break
     if flag: row.append(i)
col=[]
for i in range(w):
     flag=False
     for j in range(h):
         if(a[j][i]=='#'):
             flag=True
             break
     if flag: col.append(i)
for i in row:
    s=''
    for j in col:
        s+=a[i][j]
    print(s)