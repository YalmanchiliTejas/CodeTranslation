H,W=map(int,input().split())
A=[]
for h in range(H):
    A.append(list(map(str,input().split())))
A = [a for a in A if "#" in a[0]]
del_l=[]
for w in range(W):
    s="".join([a[0][w] for a in A])
    if "#" not in s:
        del_l.append(w)
for a in A:
    for w in range(W):
        if w not in del_l:
            print(a[0][w],end="")
    print()

