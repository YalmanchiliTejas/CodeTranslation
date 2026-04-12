import sys
sys.setrecursionlimit(10**7)

readline = sys.stdin.buffer.readline
def readstr():return readline().rstrip().decode()
def readstrs():return list(readline().decode().split())
def readint():return int(readline())
def readints():return list(map(int,readline().split()))
def printrows(x):print('\n'.join(map(str,x)))
def printline(x):print(' '.join(map(str,x)))

n = readint()
a = readints()

mod = 10**9+7
s = sum(a)
ans = 0

for i in range(n):
    s-=a[i]
    ans += a[i]*s
    ans %= mod

print(ans)
