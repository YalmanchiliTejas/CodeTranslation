import numpy as np
N = int(input().strip('\n'))
lis = []
for i in range(N):
    lis.append(int(input().strip('\n')))
lis = np.sort(np.array(lis))
mx_n = lis[-1]
ms_n = lis[0]
lis = lis[1:-1]
point = mx_n-ms_n
while lis.shape[0]>=2:
    mx = lis[-1]
    ms = lis[0]
    point += (mx_n-ms+mx-ms_n)
    mx_n = mx
    ms_n = ms
    lis = lis[1:-1]
if lis.shape[0]==1:
    point += max(abs(mx_n-lis[0]),abs(ms_n-lis[0]))
print(point)