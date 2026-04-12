import numpy as np
h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]
grid2 = []
ans = []
cur = 0
for a in grid:
    if "#" in a:
        grid2.append(a)
t_grid2 = np.array(grid2).T.tolist()
for a in t_grid2:
      if "#" in a:
        ans.append(a)
ans = np.array(ans).T.tolist()
for i in range(len(ans)):
  out = "".join(ans[i])
  print(out)