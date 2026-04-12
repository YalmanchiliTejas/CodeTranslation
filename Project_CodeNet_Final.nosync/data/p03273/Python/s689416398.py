import numpy as np
H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
ans = []
for i in range(H):
    if set(a[i]) != set("."):
        ans.append(a[i])
a = list(np.array(ans).T)
ans = []
for i in range(len(a)):
    if set(a[i]) != set("."):
        ans.append(a[i])
ans = list(np.array(ans).T)
for res in ans:
    print("".join(res))
