import numpy as np
N = int(raw_input())
line = np.array(map(int,raw_input().split()))

line2 = np.sort(line)
t = (float(line2[N / 2 -1]) + float(line2[N / 2])) / 2

for i in range(N):
    if line[i] < t:
        print line2[N / 2]
    else:
        print line2[N / 2 - 1]