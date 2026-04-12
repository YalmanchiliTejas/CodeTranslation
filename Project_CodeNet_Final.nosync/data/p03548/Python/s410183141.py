from itertools import permutations

def inpl(): return list(map(int, input().split()))

x, y, z = inpl()
print(x//(y+z) - int(x%(y+z)<z))