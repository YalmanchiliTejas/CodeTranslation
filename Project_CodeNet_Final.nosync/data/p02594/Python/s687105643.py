import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0

n = int(readline())

if n >= 30:
    print("Yes")
else:
    print("No")