# solution
import io
import math
import itertools as it

nim,mike = map(int, input().split())

arrat = []

for i in range(mike):
    a,b = map(int, input().split())
    arrat.append([a,b])

per = it.permutations(range(2,nim+1),nim-1)

result = 0

for pe in per:
    Flag = True
    pe = list(pe)
    pe.insert(0,1)
    for i in range(len(pe)-1):
        if [pe[i],pe[i+1]] not in arrat and [pe[i+1],pe[i]] not in arrat:
            Flag = False
            break
    if Flag == True:
        result +=1

print(result)