# ABC 078
def getIntList(): return [int(x) for x in input().split()]
X,Y,Z = getIntList()
n = (X-Z)//(Y+Z)
print(n)