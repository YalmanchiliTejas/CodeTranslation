h, w = map(int, input().split())
A = [input() for i in range(h)]

updated = True
while updated:
    updated = False
    newA = []
    for i in range(len(A)):
        if len(set(A[i])) == 1 and A[i][0] == '.':
            updated = True
        else:
            newA.append(A[i])
    A = newA
    newA = []
    for j in range(len(A[0])):
        tmp = [A[i][j] for i in range(len(A))]
        if len(set(tmp)) == 1 and A[0][j] == '.':
            updated = True
        else:
            newA.append(tmp)
    A = [['.' for j in range(len(newA))] for i in range(len(newA[0]))]
    for i in range(len(newA)):
        for j in range(len(newA[i])):
            A[j][i] = newA[i][j]
#     print()
#     for i in range(len(A)):
#         print("".join(A[i]))
# print()

for i in range(len(A)):
    print("".join(A[i]))
