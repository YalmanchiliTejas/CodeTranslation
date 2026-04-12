import numpy as np

h,w = list(map(int,input().split()))

def tra(a):
    b = []
    for ax in a:
        if ax == '#':
            b.append(1)
        else:
            b.append(0)
    b = np.array(b)
    return b

aa = []
for i in range(h):
    a = input()
    aa.append(tra(a))

aa_ori = np.vstack(aa)

while True:
    ind = np.sum(aa_ori,axis=0) > 0
    if np.sum(ind) == len(ind):
        break
    aa_ori = aa_ori[:,ind]

    ind = np.sum(aa_ori,axis=1) > 0
    if np.sum(ind) == len(ind):
        break
    aa_ori = aa_ori[ind,:]

for a in aa_ori:
    s = ''
    for b in a:
        if b == 1:
            s += '#'
        else:
            s += '.'
    print(s)


