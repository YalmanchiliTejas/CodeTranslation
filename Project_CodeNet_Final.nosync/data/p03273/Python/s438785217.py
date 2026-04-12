h, w = map(int, input().split())
l = [input() for i in range(h)]
l = [s for s in l if s.count("#") > 0]
check = [True] * w
for i in range(len(l[0])):
    check_row = True
    for j in range(len(l)):
        if l[j][i] == "#":
            check_row = False
    check[i] = check_row
ans = []
for i in range(len(l)):
    str_row = ""
    for j in range(len(l[0])):
        if not(check[j]):
            str_row += l[i][j]
    ans.append(str_row)
for i in range(len(ans)):
    print(ans[i])