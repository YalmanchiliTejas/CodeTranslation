H,W=map(int,input().split())
hw=[]
for _ in range(H):
    hw.append(input())

yoko_list=[]
tate_list=[]
for i in range(H):
    for j in range(W):
        if hw[i][j]=="#":
            break
        elif j==W-1:
            yoko_list.append(i)

for i in range(W):
    for j in range(H):
        if hw[j][i]=="#":
            break
        elif j==H-1:
            tate_list.append(i)

for i in range(H):
    if not i in yoko_list:
        p=0
        for j in range(W):
            if not j in tate_list:
                p+=1
                if p==W-len(tate_list):
                    print(hw[i][j])
                else:
                    print(hw[i][j],end="")