H,W = map(int,input().split())
mas = [list(input()) for i in range(H)]
new_mas = []
new_mas2 = []
for row in mas:
    if "#" in row:
        new_mas.append(row)
    elif "#" not in row:
        continue

for column in list(zip(*new_mas)):
    if "#" in column:
        new_mas2.append(column)
    elif "#" not in column:
        continue

for i in list(zip(*new_mas2)):
    for j in i:
        print(j,end="")
    print()