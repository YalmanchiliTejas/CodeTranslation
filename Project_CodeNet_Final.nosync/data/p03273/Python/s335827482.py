H,W = map(int,input().split())
A = [input() for i in range(H)]
ans = []
for i in range(H):
    flag = 0
    for j in range(W):
        if A[i][j] == "#":
            flag = 1
    if flag == 1:
        ans.append(A[i])
H2 = len(ans)
W2 = len(ans[0])
ans2 = []
for j in range(W2):
    flag = 0
    for i in range(H2):
        if ans[i][j] == "#":
            flag = 1
    if flag == 1:
        ans2.append(j)
Ans = []  
for i in range(H2):
    Ans.append([])
    for j in ans2:
        Ans[i].append(ans[i][j])
        
W3 = len(Ans[0])
for i in range(H2):
    tmp = ""
    for j in range(W3):
        tmp += Ans[i][j]
    print(tmp)