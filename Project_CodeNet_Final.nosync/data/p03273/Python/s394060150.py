H, W = map(int, input().split())

ans = []
# 横白の除去
for h in range(H):
    line = input()
    if "#" in line:
        ans.append(line)

H = len(ans)
W = len(ans[0])

# 縦白の除去
rem_list = []
for w in range(W):
    ver = [s[w] for s in ans]
    if "#" in ver:
        continue
    rem_list.append(w)

for h in range(H):
    new_ans = []
    for w in range(W):
        if w in rem_list:
            continue
        new_ans.append(ans[h][w])
    ans[h] = new_ans

for i in range(len(ans)):
    for j in range(len(ans[0])):
        print(ans[i][j], end="")
        if j >= len(ans[0])-1:
            print()
