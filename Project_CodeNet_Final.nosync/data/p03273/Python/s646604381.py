h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

a1 = []
for h_i in range(h):
    if "#" in a[h_i]:
        a1.append(a[h_i])

a2 = []
for w_i in range(w):
    for h_i in range(len(a1)):
        if a1[h_i][w_i] == "#":
            break
    else:
        a2.append(w_i)

for i in range(len(a2)):
    a2[i] -= i

for ele in a2:
    for h_i in range(len(a1)):
        a1[h_i].pop(ele)

for h_i in range(len(a1)):
    print("".join(a1[h_i]))
