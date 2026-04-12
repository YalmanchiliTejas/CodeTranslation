s_list = list(input())

uniq_s_list = set(s_list)

if len(uniq_s_list) > 1:
    print("Yes")
else:
    print('No')