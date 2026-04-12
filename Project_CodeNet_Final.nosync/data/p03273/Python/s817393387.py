h,w=map(int,input().split())
l=[]
for i in range(h):
    l.append(list(input()))
wl=[]
for i in range(h):
    wf=0
    for j in range(w):
        if l[i][j]=='.':
            wf+=1
    if wf<w:
        wl.append(i)
    
hl=[]
for i in range(w):
    hf=0
    for j in range(h):
        if l[j][i]=='.':
            hf+=1
    if hf<h:
        hl.append(i)
for i in wl:
    for j in hl:
        print(l[i][j],end='')
    print()
