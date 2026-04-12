import numpy as np
H, W = map(int, input().split())
lines = np.array([[i for i in input()] for _ in range(H)])
lines = lines[np.any(lines=="#", axis=1)]
lines = lines[:, np.any(lines=="#", axis=0)]

ans = ""
for i in lines:
  ans += "".join(i) + "\n"
ans = ans[:-1]
print(ans)