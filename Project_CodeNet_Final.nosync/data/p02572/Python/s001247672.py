import math
n = int(input())
li = list(map(int,input().split()))#[1, 2, 3]
snum = sum(li[1:])
#li.append(0)
#print(snum)
mod = (10**9+7)
res = 0
ren = 1

for v in li:
    res += (v*snum)
    if ren < len(li):
        snum-=li[ren]
        ren+=1
print(res%mod)