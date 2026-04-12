import numpy as np
A, B, C, X, Y = list(map(int, input().split()))

min_money = A*X + B*Y

status = np.array([X,Y,0])
delta_status = np.array([-1,-1,2])
block_status = np.array([0,0,0])
values = np.array([A,B,C])

for _ in range(max(X,Y)):
    status += delta_status
    status = np.max(np.array([status,block_status]), axis=0)
    
    tmp_money = sum(status * values)
    min_money = min(tmp_money,min_money)
print(min_money)