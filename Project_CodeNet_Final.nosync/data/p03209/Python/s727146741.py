n, x = map(int, input().split())

plist = [1]
bplist = [1]

for i in range(n):
    p = plist[i] + 2 ** (i+1)
    plist.append(p)

    bp = bplist[i] + 2 ** (i+2)
    bplist.append(bp)

ans = 0
index = n

while True:
    if index == 0:
        ans += 1
        break
    elif x > bplist[index-1] + 2:
        ans += plist[index - 1] + 1
        x -= bplist[index - 1] + 2
        index -= 1
    elif x == 1:
        break
    elif x == bplist[index-1] + 2:
        ans += plist[index-1] + 1
        break
    else:
        x -= 1
        index -= 1

print(ans)


