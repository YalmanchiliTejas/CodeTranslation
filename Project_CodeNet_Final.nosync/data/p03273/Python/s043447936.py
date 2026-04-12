t = input().split(" ")
H = int(t[0])
W = int(t[1])
list1 = []
for i in range(H):
    t = str(input())
    list1.append(t)
erase_index = []
for i in range(H):
    W_count = 0
    for j in range(W):
        if list1[i][j] == '.':
            W_count += 1
    if W_count == W:
        erase_index.append(i)
erase_char = []
for i in range(W):
    H_count = 0
    for j in range(H):
        if list1[j][i] == '.':
            H_count += 1
    if H_count == H:
        erase_char.append(i)
for i in range(len(erase_index)):
    list1.pop(erase_index[len(erase_index)-1-i])
ans = []
for i in zip(*list1):
    ans.append(list(i))
for i in range(len(erase_char)):
    ans.pop(erase_char[len(erase_char)-1-i])
answer = []
for i in zip(*ans):
    answer.append(list(i))
for i in range(len(answer)):
    s = ""
    for j in range(len(answer[i])):
        s += str(answer[i][j])
    print(s)