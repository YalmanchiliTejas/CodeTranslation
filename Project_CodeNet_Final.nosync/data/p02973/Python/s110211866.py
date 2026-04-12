n = int(input())
dat = []
for i in range(n):
    dat.append(int(input()))
res = []
res.append(0 - dat[0])

import bisect

for i in range(1, n):
    #print(res)
    a = bisect.bisect_right(res, 0 - dat[i])
    #print("a={0}".format(a))

    if a == len(res):
        res.append( (0 - dat[i]) )
    else:
        res[a] = (0 - dat[i])

print(len(res))