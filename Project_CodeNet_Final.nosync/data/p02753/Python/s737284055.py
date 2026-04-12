S = input()
tList = list(S)

firstStation = tList[0]
Monopoly = 0

for str in tList:
    if(str == firstStation):
        Monopoly = 0

    else:
        Monopoly = 1
        break

if(Monopoly == 0):
    print('No')
else:
    print('Yes')
