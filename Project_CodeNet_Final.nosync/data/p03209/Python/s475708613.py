# -*- coding utf-8 -*-

N, X = map(int, input().split())

len_l = [0] * 51
plen_l = [0] * 51

# calc len_l
len_l[0] = 1
plen_l[0] = 1
for i in range(50):
    len_l[i + 1] = 2 * len_l[i] + 3
    plen_l[i + 1] = 2 * plen_l[i] + 1

def p_num(l, x):
    if l == 0:
        return 0 if x <= 0 else 1
    elif x <= len_l[l-1] + 1:
        return p_num(l - 1, x - 1)
    elif x == len_l[l-1] + 2:
        return plen_l[l-1] + 1
    else:
        return plen_l[l-1] + 1 + p_num(l - 1, x - len_l[l-1] - 2)

print(p_num(N, X))