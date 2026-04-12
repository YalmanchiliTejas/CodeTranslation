import numpy as np 
H, W = map(int,input().split())

data = []
for i in range (H):
    temp = list(input())
    data.append(temp)

data = np.array(data)

h_true = []
for i in range (H):
    if (('#' not in data[i])  & ('.' in data[i])) == True:
        h_true.append(i)

w_true = []
for j in range (W):
    if (('#' not in data[:,j])  & ('.' in data[:,j])) == True:
        w_true.append(j)

data = np.delete(data,h_true,0)
data = np.delete(data,w_true,1)

for k in range (data.shape[0]):
    print(''.join(data[k]))
