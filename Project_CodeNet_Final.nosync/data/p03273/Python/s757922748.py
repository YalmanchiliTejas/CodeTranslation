h, w = map(int, input().split())
h_w_list = [list(input()) for i in range(h)]
h_li = []
w_li = []
for i in range(h):
    if "#" in h_w_list[i]:
        h_li.append(i)
for j in range(w):
    if "#" in [h_w_list[k][j] for k in range(h)]:
        w_li.append(j)
for i in h_li:
    for j in w_li:
        print(h_w_list[i][j], end="")
    print()

