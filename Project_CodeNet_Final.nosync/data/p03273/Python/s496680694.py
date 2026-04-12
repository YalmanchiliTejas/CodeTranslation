h, w = map(int,input().split())
a_l = [list(input()) for _ in range(h)]

h_ans = h
del_list_h = []
for i in range(h):
    for j in range(w):
        if a_l[i][j] == '#':
            break
    else:
        del_list_h.append(i)
        h_ans -= 1

for i in del_list_h[::-1]:
    del a_l[i]

del_list_w = []
for j in range(w):
    for i in range(h_ans):
        if a_l[i][j] == '#':
            break
    else:
        del_list_w.append(j)

for j in del_list_w[::-1]:
    for k in range(h_ans):
        del a_l[k][j]

for ans in a_l:
    print(''.join(ans))
