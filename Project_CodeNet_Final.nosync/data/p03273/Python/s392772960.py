h, w = [int(x) for x in input().split()]
 
temp_list = []
flag = [False] * w
for _ in range(h):
    a = input()
    if "#" not in a:
        continue
    temp_list.append(a)
    for i in range(w):
        flag[i] = flag[i] or a[i] == "#"

for temp in temp_list:
    print("".join([temp[i] for i in range(w) if flag[i]]))