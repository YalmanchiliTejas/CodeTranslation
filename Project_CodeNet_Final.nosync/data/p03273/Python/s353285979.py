h, w = (int(_) for _ in input().split())
l = [str(input()) for i in range(h)]

for si in l[:]:
    if si.count('.') == len(si):
        l.remove(si)
h = len(l)

rl = []
for i in range(w):
    tl = []
    for js in l:
        tl.append(js[i])
    rl.append(''.join(tl))

for si in rl[:]:
    if si.count('.') == len(si):
        rl.remove(si)
w = len(rl[0])

al = []
for i in range(w):
    tl = []
    for js in rl:
        tl.append(js[i])
    al.append(''.join(tl))

for si in al:
    print(si)