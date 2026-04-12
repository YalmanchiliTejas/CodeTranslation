S = input()
s_list = [i for i in S]
s_set = set(s_list)
if len(s_set) == 1:
    print('No')
else:
    print('Yes')