n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()# ソート
hashi = [a[0], a[-1]]
total = abs(a[0] - a[-1])

s = 1
e = n - 2
if n == 2:
    print(total)
    exit()
while True:
    max_diff = 0
    point = "s"
    h = "s"
    if max_diff < abs(hashi[0] - a[s]):
        max_diff = abs(hashi[0] - a[s])
        point = "s"
        h = "s"
    if max_diff < abs(hashi[0] - a[e]):
        max_diff = abs(hashi[0] - a[e])
        point = "e"
        h = "s"
    if max_diff < abs(hashi[1] - a[s]):
        max_diff = abs(hashi[1] - a[s])
        point = "s"
        h = "e"
    if max_diff < abs(hashi[1] - a[e]):
        max_diff = abs(hashi[1] - a[e])
        point = "e"
        h = "e"
    total += max_diff
    if h == "s":
        if point == "s":
            hashi[0] = a[s]
        if point == "e":
            hashi[0] = a[e]
    if h == "e":
        if point == "s":
            hashi[1] = a[s]
        if point == "e":
            hashi[1] = a[e]
    if point == "s":
        s += 1
    if point == "e":
        e -= 1
    if s - 1 == e:
        break
print(total)