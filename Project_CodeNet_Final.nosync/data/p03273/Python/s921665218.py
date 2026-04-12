h,w = map(int,input().split())

a = []
for _ in range(h):
    wk = input()

    if '#' in wk:
        a.append(wk)

t = []
for j in zip(*a):
    if '#' in j:
        t.append(j)

for list in zip(*t):
    print("".join(list))