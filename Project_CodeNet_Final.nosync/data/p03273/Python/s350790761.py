h,w=map(int,input().split())
a=[[1 if s=='#' else 0 for s in input()] for i in range(h)]
H=[]
W=[]
at=list(map(list,zip(*a)))
for i in range(h):
    if sum(a[i])==0:
        H.append(i)
for i in range(w):
    if sum(at[i])==0:
        W.append(i)
ans=[]
for i in range(h):
    if i not in H:
        ans.append([])
        for j in range(w):
            if j not in W:
                if a[i][j]==1:
                    ans[-1].append('#')
                else:
                    ans[-1].append('.')
for i in range(len(ans)):
    print(''.join(ans[i]))
