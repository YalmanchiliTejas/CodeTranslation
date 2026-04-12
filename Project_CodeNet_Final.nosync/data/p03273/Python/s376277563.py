
h,w = map(int,input().split())
li = []
del_r = []
del_c = []
for i in range(h):
    li.append(list(input()))
    #print(i)
    
    for j in range(w):
        if li[i][j] == '#':
            break
            
        if li[i][j] == '.' and j == w-1:
            del_r.append(int(i))

for j in range(w):
    for i in range(h):
        if li[i][j] == '#':
            break
        if li[i][j] == '.' and i == h-1:
            del_c.append(int(j))
            
#print(del_r)
#print(del_c)

for i in range(h):
    if i in del_r:
        continue
    for j in range(w):
        if j in del_c:
            continue
        print(li[i][j], end="")
    print("")
            