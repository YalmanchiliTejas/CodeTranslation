import os
import sys
from atexit import register
from io import BytesIO
sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))
input = lambda: sys.stdin.readline().rstrip('\r\n')
raw_input = lambda: sys.stdin.readline().rstrip('\r\n')

n = int(input())
seq = [int(x) for x in input().split()]
s = sum(seq[1:])
ans = 0
m = 10**9 + 7
for i in xrange(n-1):
    ans = (ans + (seq[i] * s)) % m
    s -= seq[i+1]
print(ans)