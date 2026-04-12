H,W = map(int,input().split())


H_flag = [False]*H
W_flag = [False]*W


_map = []
for i in range(H):
    x = list(input())
    _map.append(x)
    for j in range(W):
        if x[j] == '#':
            H_flag[i] = True

for i in range(W):
    for j in range(H):
        if _map[j][i] == '#':
            W_flag[i]= True

for i in range(H):
    for j in range(W):
        if H_flag[i] and W_flag[j]:
            print(_map[i][j],end="")
    if H_flag[i] :
        print()

#print(H_flag)
#print(W_flag)

