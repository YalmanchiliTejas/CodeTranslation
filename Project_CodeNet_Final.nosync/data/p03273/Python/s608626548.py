import numpy as np
import copy

h, w = map(int,input().split())
lst = [input() for i in range(h)]

array = np.zeros((h,w))
for n, i in enumerate(lst):
    for m, j in enumerate(i):
        array[n][m] = 1if j == '#' else 0

while True:
    origin = copy.deepcopy(array)
    array = array[:, array.sum(axis=0) > 0]
    array = array[array.sum(axis=1)>0, :]
    if array.shape == origin.shape:
        break

for i in array:
    string = ''
    for j in i:
        string += '#' if j == 1 else '.'
    print(string)