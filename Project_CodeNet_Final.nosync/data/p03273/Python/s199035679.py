
H, W = map(int, input().split())

C = []

for i in range(H):
    temp = input()

    for i in temp:
        if i != '.':
            C.append(temp)
            break

WB = [0] * W

for i in range(len(C)):
    for j in range(W):
        if C[i][j] == '.':
            WB[j] += 1

for i in range(len(C)):
    for j in range(W):
        if WB[j] != len(C):
            print(C[i][j], end='')
    print()
