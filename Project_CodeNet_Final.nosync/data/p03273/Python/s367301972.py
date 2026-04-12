import numpy as np

H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

def del_blank_row(a):
    del_flg = []
    for row in range(len(a)):
        if a[row].count(".") == len(a[row]):
            del_flg.append(1)
        else:
            del_flg.append(0)
    a = [a[idx] for idx in range(len(a)) if del_flg[idx] == 0]
    return a

a = del_blank_row(a)
a = np.array(a).T.tolist()
a = del_blank_row(a)
a = np.array(a).T.tolist()

for row in range(len(a)):
    print("".join(a[row]))