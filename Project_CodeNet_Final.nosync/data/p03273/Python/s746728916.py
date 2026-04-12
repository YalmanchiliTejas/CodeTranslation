def func(A,H,W):
    H_del=[]
    W_del=[]
    for h in range(H):
        if A[h][0]=='.':
            g=1
            for w in range(1,W):
                if A[h][w]!='.':
                    g=0
                    break
            if g==1:
                H_del.append(h)
    for w in range(W):
        if A[0][w]=='.':
            g=1
            for h in range(1,H):
                if A[h][w]!='.':
                    g=0
                    break
            if g==1:
                W_del.append(w)
    return H_del,W_del

def show(A,H_del,W_del,H,W):
    for h in range(H):
        if h in H_del:
            continue
        for w in range(W):
            if w in W_del:
                continue
            print(A[h][w],end='')
        print('')
H,W=map(int,input().split())
A=[]
H_del=[]
W_del=[]
for i in range(H):
    A.append(list(input()))
H_del,W_del=func(A,H,W)
show(A,H_del,W_del,H,W)
