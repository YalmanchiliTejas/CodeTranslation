
n = int(input())
listForList = []

index = 0
while index < n:
    listI = list(input())
    listI.sort()
    listForList.append(listI)
    index += 1

if len(listForList) == 1:
    print("".join(listForList[0]))
else:
    index2 = 0
    pendingL = []
    while index2 < len(listForList)-1:
        if index2 == 0:
            for c in listForList[index2]:
                if c in listForList[index2+1]:
                    pendingL.append(c)
        else:
            newPL = []
            for ch in pendingL:
                if ch in listForList[index2+1]:
                    newPL.append(ch)
                    listForList[index2+1].remove(ch)
            pendingL = newPL
            if pendingL == []:
                print("")
                break
        index2 += 1

    if index2 == len(listForList)-1:
        print("".join(pendingL))
