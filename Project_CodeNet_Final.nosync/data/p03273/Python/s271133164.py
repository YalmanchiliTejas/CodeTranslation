#107_B
H,W=map(int,input().split())
A=[]
for _ in range(H):
    S=input()
    if set(S)=={'.'}:
        continue
    A.append(list(S))
for w in range(W-1,-1,-1):
    flg=True
    for h in range(len(A)):
        if A[h][w]=='#':
            flg=False
    if flg:
        for h in range(len(A)):
            A[h].pop(w)

for s in A:
    print(''.join(s))