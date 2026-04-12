import sys
import numpy as np

pin = np.fromstring(sys.stdin.buffer.read(), dtype=np.int32, sep='\n')
N = pin[0]
a = pin[1:]
b = -1 -a
c = np.zeros(N, dtype=np.int32)
for d in b:
    i = np.searchsorted(c, d, side='right')
    c[i] = d

print((c < 0).sum())