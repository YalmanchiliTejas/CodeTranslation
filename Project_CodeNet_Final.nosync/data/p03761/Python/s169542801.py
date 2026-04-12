import sys
def 解():
    iN = int(input())
    aS = [_.rstrip() for _ in sys.stdin.readlines()]
    def buildDic(s):
        d = {}
        aABC = sorted(set(list(s)))
        for es in aABC:
            d[es]= s.count(es)
        return d
    d0 = buildDic(aS[0])
    for s in aS[1:]:
        aABC = sorted(set(list(s)))
        for ts in set(d0.keys()) - set(aABC):
            del d0[ts]
        for ts in aABC:
            if ts in d0:
                i = min(d0[ts],s.count(ts))
                if i :
                    d0[ts] = i
                else:
                    del d0[ts]
            if len(d0) == 0:
                print("")
                exit()
    aNS = sorted(d0.keys())
    sR = ""
    for ts in aNS:
        sR += ts * d0[ts]
    print(sR)
解()
