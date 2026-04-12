H, W = map(int, input().split())
matrix = [str(input()) for i in range(H)]


matrix_1 = []
for i in range(H):
    if matrix[i] != "." * W:
        matrix_1.append(matrix[i])


matrix_2 = []
for i in range(W):
    a = ""
    for l in range(len(matrix_1)):
        a += matrix_1[l][i]
    matrix_2.append(a)


ans = []
k = len(matrix_1)
for i in range(W):
    if matrix_2[i] != "." * k:
        ans.append(matrix_2[i])


ans_2 = []
for i in range(len(ans[0])):
    a = ""
    for l in range(len(ans)):
        a += ans[l][i]
    ans_2.append(a)


for i in range(len(ans_2)):
    print(ans_2[i])