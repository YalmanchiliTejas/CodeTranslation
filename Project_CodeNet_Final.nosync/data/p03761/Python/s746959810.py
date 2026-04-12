import numpy as np
N = int(input())
appearences = np.array([2501] * 26, dtype=np.int16)
for _ in range(N):
    temp = np.zeros((26,), dtype=np.int16)
    for c in input():
        i = ord(c) - ord("a")
        temp[i] += 1
    np.minimum(appearences, temp, out=appearences)
for i in range(26):
    if appearences[i] in [0, 2501]:
        continue
    print(chr(i + ord("a")) * appearences[i], end="")
print()
