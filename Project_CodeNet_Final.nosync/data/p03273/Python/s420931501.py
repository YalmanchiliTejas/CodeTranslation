import sys
def こたえ():
    H,W = [int(_) for _ in input().split()]
    aM = [_.rstrip() for _ in sys.stdin.readlines()]
    aH = [True]*H
    aW = [True]*W
    for i in range(H):
        bH = True
        for j in range(W):
            bW = True if aM[i][j] == "." else False
            if bH and not bW:
                bH = False
            if aW[j] and  not bW :
                aW[j]=False
        aH[i] = bH
    for i in range(H):
        if not aH[i]:
            for j in range(W):
                if not aW[j]:
                    sys.stdout.write(aM[i][j])
            sys.stdout.write("\n")
こたえ()
