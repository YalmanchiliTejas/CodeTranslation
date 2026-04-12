# -*-coding: utf-8 -*-
H, W = map(int, input().split())
a = []
for i in range(H): # 文字列は扱いにくいので'.' -> 0, '#' -> 1と置換
    a.append(list(input()))
    a[i] = [0 if x == '.' else 1 for x in a[i]]

# まずは行を取り除く
new_a = []
for i in range(H):
    if sum(a[i]) != 0:
        new_a.append(a[i])

# print(2, new_a)

# 転置
new_a_t = [list(x) for x in zip(*new_a)]
# print(3, new_a_t)
# 転置した行を取り除く(元の配列の列を取り除くのと同じ)
pre_ans = []
for i in range(W):
    if sum(new_a_t[i]) != 0:
        pre_ans.append(new_a_t[i])

# print(4, pre_ans)

# 転置
pre_ans = [list(x) for x in zip(*pre_ans)]

# print(5, pre_ans)

for i in range(len(pre_ans)):
    pre_ans[i] = ['#' if x == 1 else '.' for x in pre_ans[i]]
    # print(i, pre_ans[i])
    print("".join(pre_ans[i]))