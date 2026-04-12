import math

# inputList=[]
# for i in range(6):
#     inputNum = input()
#     inputList.append(inputNum)
inputa = input().split()
# inputb = input().split()

a = int(inputa[0])
# b = int(inputa[1])
# c = int(inputa[2])

# x = int(inputb[0])
# y = int(inputb[1])

list = [7, 5, 3]

flg = 0
for i in range (len(list)):
    if a == list[i]:
        flg = 1

if flg == 0:
    print("NO")
else:
    print("YES")
