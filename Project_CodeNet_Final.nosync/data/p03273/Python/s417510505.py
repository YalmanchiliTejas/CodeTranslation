H, W = map(int, input().split())
t = []
for _ in range(H):
    x = input()
    if x != '.' * W:
        t += [x]
num = len(t)
k = []
for s in zip(*t):
    s = ''.join(s)
    if s != '.' * num:
        k += [s]
for x in zip(*k):
    print(''.join(x))