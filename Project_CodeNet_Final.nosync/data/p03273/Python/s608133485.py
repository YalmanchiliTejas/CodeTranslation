H ,W = map(int, input().split())
matrix = []
for i in range(H):
    m = list(input())
    matrix.append(m)
flag = True
while(flag):
    flag = False
    for i in range(H):
        if matrix[i].count(".")==W:
            del matrix[i]
            H -= 1
            flag = True
            break
    for i in range(W):
        cnt = 0
        for j in range(H):
            if matrix[j][i]==".":
                cnt += 1
        if cnt==H:
            for k in range(H):
                del matrix[k][i]
            flag = True
            W -= 1
            break
for i in matrix:
    print("".join(i))