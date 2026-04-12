h, w = (int(x) for x in input().split())
a = [[0 if x == "." else 1 for x in input()] for _ in range(h)]
l = []
for i in range(h):
    if sum(a[i][:]) == 0: l.append(i)
if len(l) != 0:
    l = l[::-1]
    for l_i in l:
        a.pop(l_i)
l = []
for i in range(w):
    s = 0
    for j in range(len(a)):
        s += a[j][i]
    if s == 0: l.append(i)
if len(l) != 0:
    l = l[::-1]
    for l_i in l:
        for i in range(len(a)):
            a[i].pop(l_i)
ans = [["#" if int(x) == 1 else "." for x in a[i]] for i in range(len(a))]
for ans_i in ans:
    print("".join(ans_i))