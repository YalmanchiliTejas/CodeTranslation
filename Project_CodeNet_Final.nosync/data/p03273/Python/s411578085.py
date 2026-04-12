import math
import copy
import sys

inputa = input().split()
# inputb = input().split()
# inputc = input().split()

a = int(inputa[0])
b = int(inputa[1])
# c = int(inputa[2])

# x = int(inputb[0])
# y = int(inputb[1])

# inputaList = [int(n) for n in inputa]

# inputb = input().split()
# inputbList = [int(n) for n in inputb]
#
inputList = []
inputNumList = []
for i in range(a):
    inputNum = input()
    inputNumList = list(inputNum)
    inputList.append(inputNumList)

# inputList = [int(n) for n in inputList]

# b = [int(n) for n in inputb]
# c = [int(n) for n in inputc]

# row
for i in range(len(inputList)-1, -1, -1):
    flg = True
    for j in range(len(inputList[i])):
        if inputList[i][j] =="#":
            flg = False
            break

    if flg:
        del inputList[i]

# colum
for j in range(b-1, -1, -1):
    flg = True
    for i in range(len(inputList)):
        if inputList[i][j] == "#":
            flg = False
            break

    if flg:
        for i in range(len(inputList)):
            del inputList[i][j]

for i in range(len(inputList)):
    print("".join(inputList[i]))




