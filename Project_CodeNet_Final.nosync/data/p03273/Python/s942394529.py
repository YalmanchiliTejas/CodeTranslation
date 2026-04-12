h, w = map(int, input().split())
a = [input() for i in range(h)]

list_h = []
for i in range(len(a)):
    if '#' not in a[i]:
        list_h.append(i)

list_w = []
for i in range(len(a[0])):
    if a[0][i] == '.':
        for j in range(len(a)):
            if a[j][i] == '#':
                break
        else:
            list_w.append(i)

for i in range(len(a)):
    if i not in list_h:
        for j in range(len(a[0])):
            if j not in list_w:
                print(a[i][j], end='')
        else:
            print('')