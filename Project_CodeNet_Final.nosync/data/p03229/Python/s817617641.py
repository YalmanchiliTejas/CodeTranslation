import sys
iN = int(input())

aA = sorted([int(_) for _ in sys.stdin.readlines()])

#とりあえず公式の解法で解答作りまっす

if iN % 2 == 0:
    iH = iN // 2
    print( -2 * sum(aA[0:iH-1]) - aA[iH-1] + aA[iH] + 2* sum(aA[iH+1:]))
else:
    iH = (iN -1) //2
    iBigStart = -2 * sum(aA[0:iH]) + aA[iH] + aA[iH+1] + 2 * sum(aA[iH+2:])
    iSmallStart = -2 * sum(aA[0:iH-1]) - aA[iH-1] -aA[iH] + 2* sum(aA[iH+1:])
    print(max(iBigStart,iSmallStart))

exit()
