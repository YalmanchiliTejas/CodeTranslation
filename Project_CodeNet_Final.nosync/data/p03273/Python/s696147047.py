from sys import stdin
import numpy as np

h,w= [int(x) for x in stdin.readline().rstrip().split()]

li = [["" for i in range(w)]for j in range(h)]

for i in range(h):
    s = stdin.readline().rstrip()
    for j in range(w):
        li[i][j] = s[j]

li = np.asarray([s for s in li if s != ['.']*w]).T.tolist()
li = np.asarray([s for s in li if s != ['.']*len(li[0])]).T.tolist()

for i in li:
    s = ""
    for j in range(len(li[0])):
        s += i[j]
    print(s)