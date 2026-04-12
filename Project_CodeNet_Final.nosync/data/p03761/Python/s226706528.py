n = int(input())

array = []
S = input()
for i in range(len(S)):
    array.append(S[i])

for _ in range(1, n):
    S = input()
    newArray = []
    for i in range(len(S)):
        if S[i] in array:
            newArray.append(S[i])
            array.remove(S[i])

    array = [newArray[i] for i in range(len(newArray))]

array.sort()

for i in array:
    print(i, end='')

print()
