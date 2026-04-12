import numpy as np

h, w = [int(i) for i in input().split()]
a = np.array([list(input()) for _ in range(h)])

print("Possible" if np.count_nonzero(a == '#') == h+w-1 else "Impossible")
