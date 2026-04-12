H, W = map(int, input().split())
lists = [list(map(str, input())) for i in range(H)]

remove_W = []
remove_dict = {i:0 for i in range(W)}

for i in range(H):
    count_W = 0
    for j in range(W):
        if lists[i][j] == ".":
            remove_dict[j] += 1
            count_W += 1
            if count_W == W:
                remove_W.append(i)
            else:
                continue
remove_H = []
for key, value in remove_dict.items():
    if value == H:
        remove_H.append(key)

remove_H = reversed(remove_H)

for k in remove_H:
    for i in range(H):
        for j in range(W):
            if j == k:
                lists[i].pop(j)
            else:
                continue
remove_W = reversed(remove_W)
# lists_pop = [lists.remove(lists[i]) for i in remove_W]
lists_pop = [lists.pop(i) for i in remove_W]

for i in lists:
    print("".join(i))