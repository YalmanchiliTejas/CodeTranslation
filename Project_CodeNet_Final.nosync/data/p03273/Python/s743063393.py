H, W = map(int, input().split())

x = []
for _ in range(H):
    a = [c for c in input()]
    if '#' in a:
        x.append(a)

ans = []
for a in list(zip(*x)):
    if '#' in a:
        ans.append(a)

for a in list(zip(*ans)):
    print(''.join(a))