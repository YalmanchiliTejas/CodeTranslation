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

# 転置する関数
def reverse(w, h, input, output):
    for i in range(w):
        for j in range(h):
            output[i] = output[i] + input[j][i]

delete(H, A, v_list)

reverse(W, len(v_list), v_list, reverse_list)

delete(W, reverse_list, h_list)

result_list = [""]*(len(h_list[0]))

reverse(len(h_list[0]), len(h_list), h_list, result_list)

for s in result_list:
    print(s)
