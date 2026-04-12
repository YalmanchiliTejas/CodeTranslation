#!/usr/bin/python3
import copy

r = 998244353

(n, s) = map(int, input().split())

a = list(map(int, input().split()))

# s => comb
itbl = {}
rtbl = {}

for i in range(n):
    ai = a[i]
    
    if ai <= s:
        nitbl = copy.copy(itbl)        
        if ai in nitbl:
            nitbl[ai] = (nitbl[ai] + i + 1) % r
        else:
            nitbl[ai] = i + 1

        if ai in rtbl:
            rtbl[ai] += (i + 1) * (n - i)
        else:
            rtbl[ai] = (i + 1) * (n - i)

        for sk in itbl:
            if sk + ai <= s:
                if sk + ai in nitbl:
                    nitbl[sk + ai] = (nitbl[sk + ai] + itbl[sk]) % r
                else:
                    nitbl[sk + ai] = itbl[sk]
                    
                if sk + ai in rtbl:
                    rtbl[sk + ai] = (rtbl[sk + ai] + itbl[sk] * (n - i)) % r
                else:
                    rtbl[sk + ai] = (itbl[sk] * (n - i)) % r
            
        itbl = nitbl
    
print(rtbl.get(s, 0))
