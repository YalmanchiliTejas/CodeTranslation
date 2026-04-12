H,W=map(int,input().split())
f=lambda S,L:"".join(map(lambda x:S[x],L))
S=[]

B=[]
for w in range(H):
    K=input()
    S.append(K)

    if K.count("#"):
        B.append(w)
        

A=[]
for x in range(W):
    F=False
    for y in range(H):
        F|=(S[y][x]=="#")

    if F:
        A.append(x)
        
T=[]
for b in B:
    T.append(f(S[b],A))
print("\n".join(T))
