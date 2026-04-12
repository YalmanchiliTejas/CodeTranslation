N = int(input())
S = input()
K = int(input())

sList = list(S)
notReplace = sList[K-1]

for i in range(len(sList)):
    if sList[i] != notReplace:
        sList[i] = "*"

print("".join(sList))