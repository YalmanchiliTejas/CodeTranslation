H, W= map(int, input().split())
A = [input() for i in range(H)]

v_list = []
reverse_list = [""]*W
h_list = []

# 1行全てが "." のとき削除する関数
def delete(h, input, output):
    for i in range(h):
        if "#" in input[i]:
            output.append(input[i])

delete(H, A, v_list)

# 転置する関数
for i in range(W):
    for j in range(len(v_list)):
        reverse_list[i] = reverse_list[i] + v_list[j][i]


delete(W, reverse_list, h_list)

result_list = [""]*(len(h_list[0]))

# 転置する関数
for i in range(len(h_list[0])):
    for j in range(len(h_list)):
        result_list[i] = result_list[i] + h_list[j][i]

for s in result_list:
    print(s)
