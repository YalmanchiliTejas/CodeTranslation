import numpy as np

h, w = map(int, input().split())
grid = np.array([[j for j in input()] for i in range(h)])
grid = np.array([x for x in grid if "#" in x])
grid = np.array([x for x in grid.T if "#" in x])

[print("".join(x)) for x in grid.T]

  
    