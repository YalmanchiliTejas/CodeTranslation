H,W=map(int,input().split())

MAP=[None]*H

for i in range(H):
    MAP[i]=input()


ANSH=[]
for i in range(H):
    if "#" in MAP[i]:
        ANSH.append(i)

ANSW=[]
for i in range(W):
    check=0
    for j in range(H):
        if MAP[j][i]=="#":
            check=1

    if check==1:
        ANSW.append(i)


for i in ANSH:
    for j in ANSW:
        print(MAP[i][j],end="")

    print()
        
