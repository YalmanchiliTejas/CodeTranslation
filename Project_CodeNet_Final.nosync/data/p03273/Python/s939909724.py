h, w = map(int, input().split())

l = []
ll = [[True for i in range(w)] for j in range(h)]
for _ in range(h):
    s = input()
    cells = list(s)
    # print(cells)
    l.append(cells)
    
# print(l)

for h_i in range(h):
    flag = True
    for w_i in range(w):
        # print(l[h_i][w_i])
        if l[h_i][w_i] == "#":
            flag = False
            break
    if flag:
        for w_i in range(w):
            ll[h_i][w_i] = False

for w_i in range(w):
    flag = True
    for h_i in range(h):
        # print(l[h_i][w_i])
        if l[h_i][w_i] == "#":
            flag = False
            break
    if flag:
        for h_i in range(h):
            ll[h_i][w_i] = False
            
# print(ll)

for i in range(h):
    lll = []
    for j in range(w):
        # print(l[i][j])
        if ll[i][j]:
            lll.append(l[i][j])
    if len(lll) > 0:
        print(''.join(lll))