# 黒がある行と列を把握すればいい。
def ch(info,w): #もらったリストに黒が入ってるかを確認
    c=0
    for i in range(w):
        if info[i]=="#":
            c=1
            break
    return c

h,w=map(int,input().split())
info=[]
black=[]
hl=0
for i in range(h):
    s=list(input())
    if ch(s,w)==1:
        info.append(s)
        hl+=1
#print(info)
for i in range(hl):
    for j in range(w):
        if info[i][j]=="#":
            black.append(j)
for i in range(hl):
    for j in range(w):
        if j in black:
            print(info[i][j],end="")
    print("\n")