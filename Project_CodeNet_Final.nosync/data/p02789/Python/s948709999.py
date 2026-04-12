def LI():
  return [int(s) for s in input().split()]
N,M = LI()

print('Yes') if N==M else print('No')