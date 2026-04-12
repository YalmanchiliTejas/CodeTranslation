n,m=map(int,input().split())
yoko=[input() for i in range(n)]
yokosiro=[0 if "#" in yoko[i] else 1 for i in range(n)]
tatesiro=[]
for i in range(m):
    ta=[0 if yoko[j][i]=="#" else 1 for j in range(n)]
    if 0 in ta:
        tatesiro.append(0)
    else:
        tatesiro.append(1)
for i in range(n):
    if yokosiro[i]==0:
        print("".join([yoko[i][j] for j in range(m) if tatesiro[j]==0]))