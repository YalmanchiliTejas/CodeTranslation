H, W = map(int, input().split())

a = []
for i in range(H):
    a.append(input())

#print(a)

row_list = []
col_list = []
for i in range(H):
    for j in range(W):
        if a[i][j] == "#":
            row_list.append(i)
            col_list.append(j)

for i in range(H):
    ans = ""
    for j in range(W):
        if (i in row_list) and (j in col_list):
            ans += a[i][j]
    if(len(ans) > 0):
        print(ans)







