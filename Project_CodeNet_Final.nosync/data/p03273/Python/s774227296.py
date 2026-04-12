h,w = map(int,input().split())
masu = []
for i in range(h):
    tmp = list(str(input()))
    masu.append(tmp)
count = 0
for i in range(len(masu)):
    if '#' not in masu[i - count]:
        del masu[i - count]
        count += 1

count = 0
x = int(len(masu[0]))
for i in range(x):
    tmp = []
    for j in range(len(masu)):
        tmp.append(masu[j][i - count])
    if '#' not in tmp:
        for k in range(len(masu)):
            del masu[k][i - count]
        count += 1

for i in masu:
    print(''.join(i))
     