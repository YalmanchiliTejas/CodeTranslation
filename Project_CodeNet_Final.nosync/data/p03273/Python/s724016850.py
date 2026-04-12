h, w = map(int, input().split())

arr_all = []
arr_del = []
for i in range(h):
    arr_w = input()
    if list(set(arr_w)) == ["."]:
        continue
    else:
        arr_all.append(arr_w)
        arr_del.append([])


d = []

for i in range(w):
    for j in range(len(arr_all)):
        if arr_all[j][i] == ".":
            if j == w - 1:
                break
            else:
                continue
        else:
            d.append(i)
            break

for j in range(len(arr_all)):
    for i in d:
        arr_del[j] += arr_all[j][i]


for i in range(len(arr_all)):
    print(''.join(arr_del[i]))