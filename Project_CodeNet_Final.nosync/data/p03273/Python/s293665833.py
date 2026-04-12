H, W = map(int, input().split())
a_li = [input() for i in range(H)]
li = []
for i in range(H) :
    if "#" in a_li[i] :
        li.append(a_li[i])
del_nums = []
for i in range(W) :
    col_li = [row[i] for row in li]
    if not "#" in col_li :
        del_nums.append(i)
for l in li :
    for i in range(W) :
        if not i in del_nums :
            print(l[i],end="")
    print()
