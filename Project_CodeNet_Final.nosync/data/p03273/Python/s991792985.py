h,w = map(int,input().split())
hw = []

for _ in range(h):
    t = input()
    if t=='.'*w: continue
    hw.append(t)
h=len(hw)
check=[0]*w
for i in range(h):
    for j in range(w):
        if hw[i][j]=='#' and check[j]==0:
            check[j]=1
p=0
for j in range(w):
    if check[j]==0:
        for i in range(h):
            hw[i]=hw[i][:j+p]+hw[i][j+1+p:]
        p-=1
for i in range(h):
    print(hw[i])