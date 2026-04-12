H,W = map(int,input().split())
row_list = ['' for i in range(W)]
for i in range(H):
    line = input()
    if line == '.'*W:
        continue
    else:
        for j in range(W):
            row_list[j] = row_list[j] + line[j]
line_list = []
for i in range(W):
    if row_list[i] == '.' * len(row_list[i]):
        continue
    else:
        if line_list == []:
            for j in row_list[i]:
                line_list.append(j)
        else:
            for j in range(len(row_list[i])):
                line_list[j] = line_list[j] + row_list[i][j]
for i in line_list:
    print(i)