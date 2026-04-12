H,W= list(map(int,input().split()))
M = []

for i in range(H):
    M.append(list(input()))

Hs = []
for i in range(H):
    flag = 0
    for j in range(W):
        if M[i][j]!=".":
            flag = 1
    if flag==1:
        Hs.append(i)

Ws = []
for j in range(W):
    flag = 0
    for i in range(H):
        if M[i][j]!=".":
            flag = 1
    if flag==1:
        Ws.append(j)

for i in Hs:
    out = []
    for j in Ws:
        out.append(M[i][j])
    print("".join(out))
