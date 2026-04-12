H, W = map(int, input().split())

A = [input() for i in range(H)]

row = []
column = []

for i in range(len(A)):
        for j in range(len(A[i])):
                if A[i][j] == "#":
                        row.append(i)
                        break

for i in range(W):
        for j in range(len(A)):
                if A[j][i] == "#":
                        column.append(i)
                        break


for i in range(len(A)):
        flag = True
        for j in range(len(A[i])):
                if i in row:
                        if j in column:
                                print(A[i][j], end = "")
                else:
                        flag = False
                        continue
        if flag:
                print("")