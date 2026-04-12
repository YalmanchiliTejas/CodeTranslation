tateN, YokoN = map(int,input().split())
arr = [input() for i in range(tateN)]

#縦を検索
tateline = list()
for i in range(0, tateN):
    if arr[i].find('#') != -1:
        tateline.append(i)

yokoline = list()
for j in range(0, YokoN):
    found = False
    for tate in range(0, tateN):
        if arr[tate][j] == '#': found = True
    if found : yokoline.append(j)

for t in tateline:
    prstr = ''
    for y in yokoline:
        prstr += arr[t][y]
    print(prstr)