import numpy as np
H,W = map(int, input().split())
a = [list(input()) for i in range(H)]
sub = {".": 0, "#": 1}
a = [[sub.get(x,x) for x in ai] for ai in a]
tmp = np.array(a)
tmp = tmp[:, ~(np.sum(tmp, 0) == 0)] # delete all 0 column
tmp = tmp[~(np.sum(tmp, 1) == 0), :] # delete all 0 row
sub2 = {0: ".", 1:"#"}
ans = [[sub2.get(x,x) for x in tmpi] for tmpi in tmp]
for ansi in ans:
    print("{}".format("".join(ansi)))