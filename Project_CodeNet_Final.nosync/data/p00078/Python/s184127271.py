def chekend(mc):
    for m in mc:
        if not all(m):
            return False
    return True


def solve(n):
    mc = [ [ 0 for j in xrange(n) ] for i in xrange(n)]
    px = n/2
    py = n/2 + 1
    cnt = 1
    mc[py][px] = cnt
    px += 1
    py += 1
    cnt += 1
    while True:
        if chekend(mc): break
        if px >= n: px = 0; continue
        if px < 0: px = n-1; continue
        if py >= n: py = 0; continue
        if mc[py][px]: px -= 1; py += 1; continue
        mc[py][px] = cnt
        cnt += 1
        px += 1
        py += 1

    for m in mc:
        line = ""
        for l in m:
            line += "%4d"%(l)
        print line
while True:
    n = input()
    if n == 0:
        break
    solve(n)