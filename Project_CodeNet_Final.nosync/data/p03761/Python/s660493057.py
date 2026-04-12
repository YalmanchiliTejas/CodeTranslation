import sys
def 解():
    iN = int(input())
    aS = [_.rstrip() for _ in sys.stdin.readlines()]

    def buildDic(s):
        d = {}
        for es in s:
            if es in d:
                d[es] += 1
            else:
                d[es] = 1
        return d


    d0 = buildDic(aS[0])
    for s in aS[1:]:
        ed = buildDic(s)
        for ts in ed:
            if ts in d0:
                i = min(d0[ts],ed[ts])
                if i :
                    d0[ts]=i
                else:
                    del d0[ts]
        for ts in set(d0.keys()) - set(ed.keys()):
            del d0[ts]

        if len(d0) == 0 :
            print("")
            exit()
    aNS = sorted(d0.keys())
    sR = ""
    for ts in aNS:
        sR += ts * d0[ts]
    print(sR)
解()

