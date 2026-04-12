h, w = map(int,input().split())
arr = [list(input()) for i in range(h)]
tmp = []
for i in arr:
    if "#" in i:
        tmp.append(i)
ans = [[] for i in range(len(tmp))]
for i in range(w):
    count = 0
    for j in range(len(tmp)):
        if tmp[j][i] == ".":
            count += 1
    if count < len(tmp):
        for j in range(len(ans)):
            ans[j].append(tmp[j][i])

for i in ans:
    for j in range(len(ans[0])):
        print(i[j], end="")
    print()