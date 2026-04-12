while True:
    data = input().split()
    n,a,b,c,x = int(data[0]),int(data[1]),int(data[2]),int(data[3]),int(data[4])
    if n == 0 and a == 0 and b == 0 and c == 0 and x == 0: break
    yList = input().split()
    frames = []
    bRand = x
    for i in range(0,10001):
        frames.append(bRand)
        bRand = (a * bRand + b)%c
    yCount = 0
    frameCount = -1
    for i,rand in enumerate(frames):
        if int(yList[yCount]) == rand:
            yCount += 1
            if yCount == len(yList):
                frameCount = i
                break
    print(frameCount)
