import numpy as np

a1, a2 = map(int, input().split())
mx = [[list(i) for i in input().split()] for i in range(a1)]
mx = np.reshape(mx,-1)
mx = [0 if i == '.' else 1 for i in mx]
mx = np.reshape(mx,[a1,a2])

w = min(np.append(sum(mx,1),sum(mx,0)))

while w == 0:
    mx = mx[np.sum(mx,1) > 0]
    mx = mx.T[np.sum(mx.T,1) > 0].T
    w = min(np.append(sum(mx,1),sum(mx,0)))

res = np.where(mx == 0 ,".","#")

for x in res:
    print(''.join(x))