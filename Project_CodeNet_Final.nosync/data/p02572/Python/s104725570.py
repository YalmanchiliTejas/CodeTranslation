def inp():
    return input()
def iinp():
    return int(input())
def inps():
    return input().split()
def miinps():
    return map(int,input().split())
def linps():
    return list(input().split())
def lmiinps():
    return list(map(int,input().split()))
def lmiinpsf(n):
    return [list(map(int,input().split()))for _ in range(n)]

n = iinp()
a = lmiinps()

ans = 0
count = 0

for i in range(n):
    count += (a[i]%(10**9+7))

for i in range(n):
    count -= a[i]
    ans += (a[i]%(10**9+7))*count


ans %= (10**9+7)

print(ans)