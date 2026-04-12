ys, xs = map(int, input().split())
mas = []
for y in range(ys):
    mas.append(list(input()))
import numpy as np
mas_new = []
mas = np.array(mas)

for ma in mas:
    if (ma == '.').sum() != xs:
        mas_new.append(ma.tolist())
        
mas = np.array(mas_new).T

mas_new = []

for ma in mas:
    if (ma == '.').sum() != mas.shape[1]:
        mas_new.append(ma.tolist())
    
mas = np.array(mas_new).T
mas = mas.tolist()
for ma in mas:
    print(''.join(ma))