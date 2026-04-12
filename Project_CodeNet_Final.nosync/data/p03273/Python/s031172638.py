#!/usr/bin/env python
import numpy as np
H, W  = map(int, input().split())
data = [input().split() for _ in range(int(H))]
data_new = np.empty((0, W))
data_ = []
for i in data:
    for h in i[0]:
        data_.append(h)        
data_ = np.array(data_).reshape(H, W)

for i in data_:
    if np.any(i == "#"):
        data_new = np.concatenate([data_new, i.reshape(1, W)])
        
data_ = data_new.T
data_new = np.empty((0, data_.shape[1]))

for i in data_:
    if np.any(i == "#"):
        data_new = np.concatenate([data_new, i.reshape(1, data_.shape[1])])

data_new = data_new.T

for i in data_new:
    i = i.tolist()
    print(''.join(i))
