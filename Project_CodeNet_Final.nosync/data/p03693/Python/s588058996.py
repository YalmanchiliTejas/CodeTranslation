# A
def getIntList(): return [int(x) for x in input().split()]
r,g,b = getIntList()
n = r*100+g*10+b
if n%4==0: print('YES')
else: print('NO')