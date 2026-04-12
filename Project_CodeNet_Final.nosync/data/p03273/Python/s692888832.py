h, w = map(int, input().split())
a = []
for i in range(h):
    ai = [j for j in input()]
    if set(ai) == {'.'}:
        continue
    a.append(ai)
len_a = len(a)
at = list(zip(*a))
at2 = []
for ati in at:
    if set(ati) != {'.'}:
        at2.append(ati)
att = list(zip(*at2))
for ai in att:
    print(*ai, sep='')