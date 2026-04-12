import sys
import numpy as np
input = sys.stdin.readline

h, w = map(int, input().split())

a = [list(input()) for _ in range(h)]

a = np.array(a)

i = 0
j = 0


while i < len(a):
    if np.sum(a[i,:] == '#') == 0:
        a = np.delete(a, i, 0)
        i -=1
    i +=1

while j < w:
    if np.sum(a[:,j] == '#') == 0:
        a = np.delete(a, j, 1)
        j -= 1
    j += 1
    h, w = a.shape



h, w = a.shape
for i in range(h):
    for j in range(w):
        print(a[i, j], end="")
    print('')
    
