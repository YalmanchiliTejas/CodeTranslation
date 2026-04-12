h,w = map(int,input().split())
f = [input()for i in range(h)]
H = []
W = []
for i in range(h):
    ok = True
    for j  in range(w):
        if f[i][j] == '#':
            ok = False
            break
    if ok:H.append(i)
for i in range(w):
    ok = True
    for j in range(h):
        if f[j][i] == '#':
            ok = False
            break
    if ok:W.append(i)
nf = []
for i in range(h):
    p = []
    for j in range(w):
        if  i in H or j in W:continue
        p.append(f[i][j])
        
    if len(p) > 0:nf.append(p)
for i in range(len(nf)):
    print("".join(nf[i]))
               
        