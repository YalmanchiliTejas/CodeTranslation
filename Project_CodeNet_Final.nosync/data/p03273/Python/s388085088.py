h, w = map(int, input().split())
a = []
for i in range(h):
    a.append([i for i in input()])
h_count = []
for h_ in range(h):
    if a[h_] == ["."] * w:
        h_count.append(h_)
w_count = []
for w_ in range(w):
    if list(map(lambda x: x[w_], a)) == ["."] * h:
        w_count.append(w_)
h_get = [i for i in range(h) if i not in h_count]
w_get = [i for i in range(w) if i not in w_count]

for i in h_get:
    temp = a[i]
    temp_1 = []
    for j in w_get:
        temp_1.append(temp[j])
    print("".join(temp_1))