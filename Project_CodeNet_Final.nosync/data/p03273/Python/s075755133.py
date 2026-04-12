h,w=map(int,input().split())
ans=[]
for i in range(h):
    x=input()
    if x!='.'*w:
        ans.append(x)
if len(ans)==0:
    print(*ans)
    exit()
flag=[0 for _ in range(w)]
for i in range(w):
    if ans[0][i]=='.':
        flag[i]=1
if len(ans)==1:
    for i in range(w):
        if flag[i]==0:
            print(ans[0][i],end='')
else:
    for i in range(1,len(ans)):
        for j in range(w):
            if flag[j]==1:
                if ans[i][j]!='.':
                    flag[j]=0
    for i in range(len(ans)):
        for j in range(w):
            if flag[j]==0:
                print(ans[i][j],end='')
        print()