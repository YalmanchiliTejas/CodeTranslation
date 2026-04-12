import numpy as np

h,w = map(int,input().split())
x = [[0 if s=="." else 1 for s in list(input())] for _ in range(h)]

for i in reversed(range(h)):
    if sum(x[i])==0:
        x.pop(i)
x = np.array(x).T.tolist()
for i in reversed(range(len(x))):
    if sum(x[i])==0:
        x.pop(i)
x = np.array(x).T.tolist()
h = range(len(x))
x = [["#" if j==1 else "." for j in x[i]] for i in h]
for i in h:
    print ("".join(x[i]))