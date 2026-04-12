import numpy as np

n,m = map(int,input().split())
out = []
for i in range(n):
    s = list(input())
    if any(c=="#" for c in s):
        out.append(s)

out = np.array(out).T
# print(out)
out2=[]
for i in range(m):
    if any(c=="#" for c in out[i]):
        out2.append(out[i])

out2=np.array(out2).T
# print(out2)

for line in out2:
    for i in range(len(line)-1):
        print(line[i],end="")
    print(line[-1])



