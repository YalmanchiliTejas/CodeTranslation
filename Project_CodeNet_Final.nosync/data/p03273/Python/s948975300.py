H, W = map(int,input().split())
S = [list(input()) for i in range(H)]

ans_h = []
for h in range(H) :
    flag = False
    for w in range(W) :
        if S[h][w] == "#" :
            flag = True
    if flag == True :
        ans_h.append(h)

ans_w = []
for w in range(W) :
    flag = False
    for h in range(H) :
        if S[h][w] == "#" :
            flag = True
    if flag == True :
        ans_w.append(w)

for h in ans_h :
    for w in ans_w :
        print(S[h][w], end="")
    print("")
