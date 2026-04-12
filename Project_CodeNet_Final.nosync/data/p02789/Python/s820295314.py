import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))

n,m = get_ints()
if n==m:
  print('Yes')
else:
  print('No')