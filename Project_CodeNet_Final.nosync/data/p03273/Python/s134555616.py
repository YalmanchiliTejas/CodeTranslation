import numpy as np
H, W = map(int, input().split())
A = [list(input()) for i in range(H)]
A = [a for a in A if "#" in a]
A = list(np.array(A).transpose())
A = [a for a in A if "#" in a]
A = list(np.array(A).transpose())
for a in A:
    print("".join(a))
