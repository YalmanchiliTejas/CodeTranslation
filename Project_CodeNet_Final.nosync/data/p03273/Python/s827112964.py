H, W = map(int, input().split())
a = []
for i in range(H):
    tmp = list(input())
    if "#" in tmp:
        a.append(tmp)

w_check = [True] * W
for i in range(len(a)):
    for j in range(W):
        if a[i][j] == "#":
            w_check[j] = False

ans = [[] for i in range(len(a))]
for i in range(len(a)):
    for j in range(W):
        if not w_check[j]:
            ans[i].append(a[i][j])

for i in ans:
    output = ""
    for j in i:
        output += j
    print(output)
