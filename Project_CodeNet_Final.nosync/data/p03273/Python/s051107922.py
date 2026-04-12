h, w = map(int, input().split())
a = [list(map(int, list(input().replace('.', '0').replace('#', '1')))) for _ in range(h)]

h_list, w_list = [], []
for i in range(h):
    if sum(a[i]) > 0:
        h_list.append(i)
for j in range(w):
    if sum([aa[j] for aa in a]) > 0:
        w_list.append(j)
for i in h_list:
    print(''.join(['.','#'][a[i][j]] for j in w_list))
