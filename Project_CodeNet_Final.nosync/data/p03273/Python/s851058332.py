# zipを使用する版

H, W = map(int, input().split())
a = []
for _ in range(H):
    tmp = list(input())
    if "#" in tmp:
        a.append(tmp)

a_reverse = list(map(list, zip(*a)))
ans = []
for tmp in a_reverse:
    if "#" in tmp:
        ans.append(tmp)

ans_list = list(map(list, zip(*ans)))

for tmp_list in ans_list:
    tmp = ""
    for tmp_val in tmp_list:
        tmp += tmp_val
    print(tmp)
