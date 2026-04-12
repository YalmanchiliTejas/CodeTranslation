N = int(input())
hLst = list(map(int, input().split()))
hMax = hLst[0]
ans = 1
for i in range(1, len(hLst)):
    if hLst[i] >= hMax:
        ans += 1
        hMax = hLst[i]

print(ans)