import sys
def 解():
    iN = int(input())
    aS = [_.rstrip() for _ in sys.stdin.readlines()]

    sABC = "abcdefghijklmnopqrstuvwxyz"
    iL = len(sABC)
    aC = [0]*iL
    for i in range(iL):
        aC[i] = aS[0].count(sABC[i])
    for s in aS[1:]:
        #b0 = True
        for i in range(iL):
            if aC[i]:
                iC = s.count(sABC[i])
                #if iC :
                #   b0 = False
                aC[i] = min(aC[i] ,iC)

        #if b0:
        #   print("")
        #   exit()

    sR = ""
    for i in range(iL):
        if aC[i]:
            sR += sABC[i] * aC[i]
    print(sR)
解()
