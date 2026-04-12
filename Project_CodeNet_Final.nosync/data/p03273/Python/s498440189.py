h, w = map(int, input().split())
arr = [input() for j in range(h)]
tarr = []
counter = 0
for i in range(h):
    if arr[i].count("#") != 0:
        counter += 1
        tarr.append(arr[i])
tans = [["" for i in range(counter)] for j in range(w)]
for i in range(counter):
    for j in range(w):
        tans[j][i] = tarr[i][j]
counter2 = 0
ttans = []
for i in range(w):
    if tans[i].count("#") != 0:
        counter2 += 1
        ttans.append(tans[i])
for i in range(counter):
    for j in range(counter2):
        print(ttans[j][i], end="")
        if j == counter2-1:
            print("")