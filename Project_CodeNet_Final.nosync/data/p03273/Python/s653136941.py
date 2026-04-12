h,w=map(int,input().split())
hw=[input() for i in range(h)]
thw=[]
for i in range(h):
    if hw[i].count('#')!=0:
        thw+=[hw[i]]
ans=['']*len(thw)
for i in range(w):
    flg=False
    for j in range(len(thw)):
        if thw[j][i]=='#':
            flg=True
            break
    if flg:
        for j in range(len(thw)):
            ans[j]+=thw[j][i]
for i in range(len(ans)):
    print(ans[i])