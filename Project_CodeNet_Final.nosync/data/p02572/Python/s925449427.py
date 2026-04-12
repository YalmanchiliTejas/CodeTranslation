import numpy as np
n = input()
a = np.array(list(map(int, input().split())), dtype=object)
print((sum(a)**2 - sum(a**2)) // 2 % (10 ** 9 + 7))
