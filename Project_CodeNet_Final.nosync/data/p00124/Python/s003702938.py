isPrint = False

while True:

    inputCount = int(input())

    if inputCount == 0:
        break

    if isPrint:
        print()
    else:
        isPrint = True

    matchList = []

    for lp in range(inputCount):

        name, win, lose, draw = [item for item in input().split(" ")]
        score = int(win) * 3 + int(draw)

        matchList.append([name, score])

    matchList.sort(key=lambda item: -item[1])

    for name, score in matchList:
        print(name + "," + str(score))

