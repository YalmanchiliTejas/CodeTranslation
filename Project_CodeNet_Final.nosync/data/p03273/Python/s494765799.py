H, W= map(int, input().split())
A = [input() for i in range(H)]

v_list = []
reverse_list = [""]*W
h_list = []

for i in range(H):
    if "#" in A[i]:
        v_list.append(A[i])

for i in range(W):
    for j in range(len(v_list)):
        reverse_list[i] = reverse_list[i] + v_list[j][i]

for i in range(W):
    if "#" in reverse_list[i]:
        h_list.append(reverse_list[i])

result_list = [""]*(len(h_list[0]))

for i in range(len(h_list[0])):
    for j in range(len(h_list)):
        result_list[i] = result_list[i] + h_list[j][i]

for s in result_list:
    print(s)
