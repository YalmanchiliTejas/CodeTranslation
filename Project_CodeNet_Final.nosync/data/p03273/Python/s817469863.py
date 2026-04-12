h,w = map(int,input().split())
map_input = [[1 if j=='#' else 0 for j in list(input())] for i in range(h)]

h_li = [0]*h
w_li = [0]*w

for i in range(h):
    for j in range(w):
        h_li[i]+=map_input[i][j]
        w_li[j]+=map_input[i][j]

for i in range(h):
    if h_li[i]==0:
        continue
    tmp=[]
    for j in range(w):
        if w_li[j]==0:
            continue
        tmp.append(map_input[i][j])
    print(''.join(['.' if k==0 else '#' for k in tmp]))