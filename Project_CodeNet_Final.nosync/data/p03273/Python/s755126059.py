h,w = map(int,input().split())
mp = [input() for i in range(h)]
mp2 = []
for i in range(h):
    if mp[i]!='.'*w:
        mp2.append(mp[i])
space = []
for i in range(w):
    flag = True
    for j in range(len(mp2)):
        flag &= (mp2[j][i]=='.')
    if flag:
        space.append(i)
for i in range(len(mp2)):
    for j in range(w):
        if j in space:
            continue
        print(mp2[i][j],end='')
    print("")
