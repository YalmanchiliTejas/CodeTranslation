import sys

XYZ= list(sys.stdin.readline().rstrip().split(" "))

TOTAL_LEN  = int(XYZ[0])
ONE_OCCUPY= int (XYZ[1])
GAP= int(XYZ[2])


MIDDLE = TOTAL_LEN - 2*GAP

HOW_MANY = 0

while MIDDLE > 0:
    MIDDLE = MIDDLE - ONE_OCCUPY
    if MIDDLE == 0:
        HOW_MANY = HOW_MANY + 1
    elif MIDDLE < 0:
        break
    else:
        HOW_MANY = HOW_MANY + 1
        MIDDLE = MIDDLE - GAP
#ANSWER = int(MIDDLE / (ONE_OCCUPY + GAP))
#ANSWER = int(TOTAL_LEN / (ONE_OCCUPY + 2*GAP))

print(HOW_MANY)