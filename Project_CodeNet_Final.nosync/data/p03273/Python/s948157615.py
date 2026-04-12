h, w = list(map(int, input().split()))
ss = []
for _ in range(h):
    s = input().strip()
    if '#' in s:
        ss.append(s)
new_h = len(ss)
dels = []
for i in range(w):
    rep = True
    for j in range(new_h):
        if ss[j][i] == '#':
            rep = False
    if rep:
        dels.append(i)
for i in range(new_h):
    now = ss[i]
    pri = []
    for j in range(w):
        if j not in dels:
            pri.append(now[j])
    print(''.join(pri))
