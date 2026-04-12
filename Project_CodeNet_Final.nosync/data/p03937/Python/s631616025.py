h,w = map(int,input().split())
a = []
cnt = 0
for _ in range(h):
    a.append(list(input()))
    cnt += a[-1].count("#")
looked = [[True for _ in range(w)]for i in range(h)]
looked[0][0] = False
x,y = 0,1
now = [0,0]
ans = 1

while(True):
    look = [[min(now[y]+1,h-1),now[x]],[now[y],min(now[x]+1,w-1)]]
    flag = 1
    for i in range(2):
        if looked[look[i][x]][look[i][y]]:
            if a[look[i][x]][look[i][y]] == "#":
                now = [look[i][y],look[i][x]]
                looked[look[i][x]][look[i][y]] = False
                ans += 1
                flag = 0
                break
    if flag:
        break
if ans == cnt and now == [w-1,h-1]:
    print("Possible")
else:
    print("Impossible")