H, W = map(int, input().split())

wlist = []

flagc = [0 for i in range(W)]
for i in range(H):
    rtmp = str(input())
    rtmp_s = list(rtmp)

    flag = 0
    for j in range(len(rtmp_s)):
        if rtmp_s[j] == '#':
            flag += 1
            flagc[j] += 1

    if flag == 0:
        pass
    else:
        wlist.append(rtmp_s)


count = 0
for i in range(W):
    if flagc[i] == 0:
        count += 1

ans = []
for i in range(len(wlist)):
    ansr = []
    k = 0
    for j in range(W):
        if flagc[j] == 0:
            pass
        else:
            ansr.append(wlist[i][k])
        k += 1

    ans.append(ansr)


for i in range(len(ans)):
    for j in range(len(ans[0])):
        print(ans[i][j], end='')
    print('')
