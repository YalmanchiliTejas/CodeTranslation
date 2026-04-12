n = int(input())
s_list = [input() for _ in range(n)]

def str_2_set(string):
    s = set()
    used_dict = {}

    for l in string:
        if l not in used_dict:
            used_dict[l] = 1
            number = 1
        else:
            used_dict[l] += 1
            number = used_dict[l]
        l = l + str(number)
        s.add(l)
    return s

set_list = [str_2_set(s) for s in s_list]
for i,s in enumerate(set_list):
    if i == 0:
        return_set = s
    else:
        return_set = return_set & s

return_list = []
while len(return_set) > 0:
    num = return_set.pop()[0]
    return_list.append(num)

return_list.sort()
print(''.join(return_list))