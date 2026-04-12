#ABC-B_not debuged
H, W = map(int, input().split())
a, ans = [], []
for i in range(H):
    temp = input()
    if temp == '.'*W:
        continue
    a.append(temp)
    ans.append([])

for i in range(W):
    for j in a:
        if j[i] == '#':
            break
    else:
        continue
    for j,k in zip(a,ans):
        k.append(j[i])
for i in ans:
    print(''.join(i))