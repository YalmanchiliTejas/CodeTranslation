n = int(input())
sl = []
for i in range(n):
    sss= list(str(input()))
    onedict = {}
    for j in range(len(sss)):
        if sss[j] in onedict:
            onedict[sss[j]] = onedict[sss[j]] + 1
        else:
            onedict.update({sss[j]:1})
    sl.append(onedict)

ansdict = {}

for alphabet in sl[0].keys():
    flag = 0
    mins = []
    for j in sl:
        if alphabet in j:
            mins.append(j[alphabet])
        else:
            flag = 1
    if flag == 1:
        None
    else:
        minutes = min(mins)
        ansdict.update({alphabet:minutes})

goalkeys = list(sorted(ansdict.keys()))
                
moji = ''
for i in goalkeys:
    for j in range(ansdict[i]):
        moji = moji + i
        
print(moji)
            