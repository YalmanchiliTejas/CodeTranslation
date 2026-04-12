h, w = list(map(int, input().split(' ')))

a = []
for i in range(h):
    line = input()
    aa = []
    for j in range(len(line)):
        aa.append(line[j])
    a.append(aa)

# horizontal
popList = []
for i in range(len(a)):
    isBlack = False
    for j in range(len(a[i])):
        if a[i][j] == "#":
            isBlack = True
    
    if isBlack == False:
        popList.append(i)

for i in range(len(popList)):
    a.pop(popList[i] - i)

# vertical
popList = []
for i in range(len(a[0])):
    isBlack = False
    for j in range(len(a)):
        if a[j][i] == "#":
            isBlack = True

    if isBlack == False:
        popList.append(i)

for i in range(len(popList)):
    for j in range(len(a)):
        a[j].pop(popList[i] - i)

# print
for i in a:
    for j in i:
        print(j, end="")
    print()