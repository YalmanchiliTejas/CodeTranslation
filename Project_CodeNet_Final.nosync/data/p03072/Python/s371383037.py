import math
import copy

inputa = input().split()
inputb = input().split()
# inputc = input().split()

a = int(inputa[0])
# b = int(inputa[1])
# c = int(inputa[2])

# a = inputa[0]
# inputList = list(a)

# x = int(inputb[0])
# y = int(inputb[1])

# inputList=[]
# for i in range(a):
#     inputNum = input()
#     inputList.append(inputNum)

b = [int(n) for n in inputb]
# c = [int(n) for n in inputc]

sum = 0
for i in range(len(b)-1, -1, -1):
    flg = True
    for j in range(i):
            if b[j] > b[i]:
               flg = False
               break
    if flg == True:
        sum += 1

print(sum)







