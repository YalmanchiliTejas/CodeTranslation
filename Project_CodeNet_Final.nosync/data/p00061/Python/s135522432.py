import sys
from collections import Counter
p=[tuple(map(int,l.split(","))) for l in sys.stdin]
d=[i for i in p if len(i)==2][:-1]

rank=sorted(Counter([i[1] for i in d]).keys(),reverse=True)
m=sorted(d,key=lambda x:x[1],reverse=True)
tix=[i[0] for i in p if len(i)==1]
[print(rank.index(k[1])+1) for k in [i for i in m for j in tix if i[0]==j]]

