h, w = map(int, input().split())
mat = []
mat_1 = []
mat_2 = []
mat_3 = []
mat_4 = []

for i in range(h):
    line = list(input())
    mat.append(line)
# print(mat)

# すべて白の行を削除
for i in range(h):
    line = mat[i]
    if line.count(".") != w:
        mat_1.append(line)

# print(mat_1)

# 転置
for line in zip(*mat_1):
    mat_2.append(list(line))

# print(mat_2, len(mat_2))
# すべて白の行を削除
for i in range(len(mat_2)):
    line = mat_2[i]
    if line.count(".") != len(mat_2[0]):
        mat_3.append(line)

# print(mat_3)

# 転置
for line in zip(*mat_3):
    mat_4.append(list(line))

# 出力
for line in mat_4:
    print(*line, sep="")
