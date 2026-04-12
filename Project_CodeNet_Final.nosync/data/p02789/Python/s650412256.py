import sys
n, m = [int (e) for e in sys.stdin.readlines()[0].split(" ")]
print("Yes" if n == m else "No")