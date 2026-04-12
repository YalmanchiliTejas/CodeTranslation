H, W = map(int, input().split())
White = "."
Black = "#"

ans = []

for i in range(H):
    S = input()
    if(S.find(Black) == -1):
        H -= 1
    else:
        ans.append(list(S))

# print(ans)
i = 0
del_row = []
while(i < W):
    tmp = ""
    for j in range(H):
        tmp += ans[j][i]
    if(tmp.find(Black) == -1):
        del_row.append(i)

    i += 1

for i in reversed(del_row):
    for j in range(H):
        ans[j].pop(i)

for i in range(H):
    print("".join(ans[i]))