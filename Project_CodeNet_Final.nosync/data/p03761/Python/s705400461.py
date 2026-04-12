n = int(input())
s_lst, s_dic_lst = [], []
min_idx = 51

for i in range(n):
    s_in = input()
    s_dic = {chr(j):0 for j in range(ord('a'), ord('a')+26)}

    if len(s_in) < min_idx:
        min_idx = i

    for j in s_in:
        s_dic[j] += 1

    s_dic_lst.append(s_dic)

min_dic = s_dic_lst[min_idx]

for i in range(n):
    if i != min_idx:
        for key in min_dic:
            if min_dic[key] > s_dic_lst[i][key]:
                min_dic[key] = s_dic_lst[i][key]

ans_lst = []

for key in min_dic:
    for j in range(min_dic[key]):
        ans_lst.append(key)

ans_lst.sort()

print("".join(ans_lst))
