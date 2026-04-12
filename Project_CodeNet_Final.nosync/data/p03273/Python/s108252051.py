H, W = map(int, input().split())
S = [input() for _ in range(H)]
T = []

for s in S:
    if '#' not in s:
        continue
    T.append(s)

S = []
for t in list(zip(*T)):
    if '#' not in t:
        continue
    S.append(t)
    
for s in list(zip(*S)):
    print(''.join(map(str, s)))