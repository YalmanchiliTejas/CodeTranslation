import sys
H,W = map(int,input().split())
array_list = []
for I in range(H):
    array_list.append(list(map(str,input())))

if not ( 1 <= H <= 100 and 1 <= W <= 100 ):
    sys.exit()

Horizon_list = []
Vertical_list = []
# Horizon check
for J in range(len(array_list)):
    if array_list[J].count('.') == W:
        Horizon_list.append(J)
# Vertical check
list_check = [list(x) for x in zip(*array_list)]
for K in range(len(list_check)):
    if list_check[K].count('.') == H:
        Vertical_list.append(K)
# print result
for L in range(H):
    for M in range(W):
        if (L not in Horizon_list ) and (M not in Vertical_list):
            print(array_list[L][M],end='')
    print('\n')