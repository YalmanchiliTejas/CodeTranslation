ABCXY = list(int(i) for i in input().split())

XY = []
XY.append(ABCXY[3])
XY.append(ABCXY[4])

ans = 0
if 2*ABCXY[2] < ABCXY[0] + ABCXY[1]:
    ans += min(XY)*2*ABCXY[2]
    if XY[0] > XY[1]:
        if ABCXY[0] < 2*ABCXY[2]:
            ans += (XY[0]-XY[1])*ABCXY[0]
        else:
            ans += (XY[0]-XY[1])*ABCXY[2]*2
    else:
        if ABCXY[1] < 2*ABCXY[2]:
            ans += (XY[1]-XY[0])*ABCXY[1]
        else:
            ans += (XY[1]-XY[0])*ABCXY[2]*2
else:
    ans += ABCXY[0]*XY[0] + ABCXY[1]*XY[1]
print(ans)
