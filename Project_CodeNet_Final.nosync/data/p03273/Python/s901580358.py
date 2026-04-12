import numpy as np

H, W = map(int, input().split())
ans = []

for _ in range(H):
    line = list(str(input()))
    if '#' not in line:
        continue
    else:
        ans.append(line)

ans = np.array(ans).T.tolist()
hoge = []
for i in range(len(ans)):
    line = ans[i]
    if '#' not in line:
        continue
    else:
        hoge.append(line)

ans = np.array(hoge).T.tolist()

for a in ans:
    print("".join(a))
