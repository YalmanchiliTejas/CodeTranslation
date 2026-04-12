from collections import deque

n=int(input())
a = []

for i in range(n):
    a.append(int(input()))

a.sort()

a=deque(a)

mid = a[(n-1)//2]
midi = abs(a[(n-1)//2-1] - mid)
mida = abs(a[(n-1)//2+1] - mid)

rev = False
omi = a[0]
oma = a[-1]

ans = abs(oma - omi)
for i in range(len(a)//2):
    mi = a.popleft()
    ma = a.pop()

    if rev:
        q = mi
        mi = ma
        ma = q

    ans+=abs(mi - omi)+abs(ma - oma)

    omi = mi
    oma = ma
    rev = not rev

if len(a)==1:
    ans+=max(midi,mida)

print(ans)