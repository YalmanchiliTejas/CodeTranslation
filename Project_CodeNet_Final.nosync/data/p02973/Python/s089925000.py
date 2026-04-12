import sys
from bisect import bisect_right, insort

def I(): return int(sys.stdin.readline())

def main():
  n = I()
  a = [I() for i in range(n)]
  b = []

  for i in range(n-1, -1, -1):
    t = bisect_right(b, a[i])
    if len(b)-1<t or b[t]==a[i]:
      insort(b, a[i])
    else:
      b[t] = a[i]
  print(len(b))

if __name__ == '__main__':
  main()