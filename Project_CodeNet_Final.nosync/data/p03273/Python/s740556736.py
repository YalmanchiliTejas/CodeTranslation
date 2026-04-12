a,b = [int(i) for i in input().split()]
l = [input() for _ in range(a)]
skip_num = []

for i in range(b):
    key_set = set()
    for j in range(a):
        key_set |= set(l[j][i])
    if key_set == set('.'):
        skip_num.append(i)
        

ans = [[] for _ in range(a)]       
for k in range(a):
    if set(l[k]) ==  set('.'):
        pass
    else:
        for i in range(b):
            if i in skip_num :
                pass
            else:
                ans[k].append(l[k][i])
                

for i in ans:
    if i :
        print(''.join(i))
                