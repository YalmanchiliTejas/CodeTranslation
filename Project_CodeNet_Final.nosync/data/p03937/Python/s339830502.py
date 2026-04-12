import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


h,w = map(int, input().split())
a = [None]*h
for i in range(h):
    a[i] = input()
cx = 0
cy = 0
d = set()
while (cx,cy)!=(h-1, w-1):
    val = 0
#     print(cx,cy)
    for dx, dy in [(1,0), (0,1)]:
        ccx = cx+dx
        ccy = cy+dy
        if ccx>=h or ccy>=w or a[ccx][ccy]==".":
            continue
        nx, ny = ccx, ccy
        val += 1
    if val>=2 or val==0:
        ans = "Impossible"
        break
    cx, cy = nx, ny
else:
    vv = sum(sum(item=="#" for item in items) for items in a)
    if vv==h+w-1:
        ans = "Possible"
    else:
        ans = "Impossible"
print(ans)