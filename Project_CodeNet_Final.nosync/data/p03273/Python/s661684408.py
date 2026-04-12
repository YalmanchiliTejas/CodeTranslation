H,W=map(int,input().split())
a=[]
for i in range(H):
    ai=input()
    if ai=="."*W:
        continue
    a.append(ai)
h=len(a)
def tenti(a):
    b=[]
    h=len(a)
    w=len(a[0])
    for i in range(w):
        bi=[]
        for j in range(h):
            bi.append(a[j][i])
        b.append(bi)
    return b
b=tenti(a)
h=len(b)
w=len(b[0])
c=[]
for i in range(h):
    if b[i]==["."]*w:
        continue
    c.append(b[i])
d=tenti(c)
for i in range(len(d)):
    for j in range(len(d[0])):
        if j==len(d[0])-1:
            print(d[i][j])
            break
        print(d[i][j],end="")
