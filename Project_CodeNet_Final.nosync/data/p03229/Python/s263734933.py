import numpy as np
import copy

N = int(raw_input().replace("\n", ""))

a_array = np.asarray(sorted([int(raw_input().replace("\n", "")) for i in xrange(N)]))

len_array = len(a_array)

coffs = np.ones(len(a_array), dtype=bool) * 2

if len_array % 2 == 0:
    coffs = [-2] * ((len_array - 1) / 2) + [-1] + [1] + [2] * ((len_array -1) / 2)
    out = np.dot(a_array, coffs)
else:
    coffs1 = [-2] * ((len_array-3) / 2) + [-1] * 2 + [2] * ((len_array-1) / 2)
    coffs2 = [-2] * ((len_array-1) / 2) + [1] * 2 + [2] * ((len_array-3) / 2)
    out1 = np.dot(a_array, coffs1)
    out2 = np.dot(a_array, coffs2)
    out = max(out1, out2)

print out
