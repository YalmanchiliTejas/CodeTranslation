H, W = map(int, input().split())
list = []
for i in range(H):
    list.append(input())

new_list = []

H_del = []
W_del = []

#削除する行列の探索
for i in range(H):
    if list[i] == '.'*W:
        W_del.append(i)

for i in range(W):
    H_stock = ''
    for j in range(H):
        H_stock += list[j][i]
        if H_stock == '.'*H:
            H_del.append(i)

#削除する行列を除いた行列を再作成
for i in range(H):
    if i not in W_del:
        W_list = ''
        for j in range(W):
            if j not in H_del:
                W_list += list[i][j]
        new_list.append(W_list)

#答えを表示
for i in range(len(new_list)):
    print(new_list[i])