from copy import deepcopy
H, W = map(int, input().split())
alist = [list(input()) for _ in range(H)]
acopy = deepcopy(alist)
counter = 0
for i in range(W):
    for a in alist:
        if a[i] == "#":
            break
    else:
        for a in acopy:
            a.pop(i - counter)
        counter += 1

for a in acopy:
    if "#" in a:
        print("".join(a))
