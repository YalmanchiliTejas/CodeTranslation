import numpy as np
h, w = map(int, input().split())

li= np.array([input() for _ in range(h)])
del_count= 0
for i in range(h):
     if li[i-del_count] == "." * w:
         li = np.delete(li, i-del_count, 0)
         del_count+=1

del_count = 0
for i in range(len(li[0])):
    for j in range(len(li)):
        if li[j][i-del_count] == "#":
            break
        elif j == len(li)-1:
            for k in range (len(li)):
                li[k] = li[k][:i-del_count]+li[k][i-del_count+1:]
            del_count+= 1
for i in li:
    print(i)