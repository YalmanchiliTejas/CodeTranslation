import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from fractions import gcd

L = int(readline())
S = readline().rstrip().decode('utf-8')
T = readline().rstrip().decode('utf-8')

ST = S + T
TS = T + S
if ST > TS:
    S,T = T,S

# Sを手前にした方が得

LS = len(S)
LT = len(T)

n = 0
for x in range(L+1):
    if (L - LS * x) % LT == 0:
        n = x
        break

n1, m1 = n, (L - LS * n) // LT
d = gcd(LS,LT)
n2, m2 = n1, m1
dn, dm = LT//d, LS//d
while m2 >= dm:
    m2 -= dm
    n2 += dn

x = S * n1 + T * m1
y = S * n2 + T * m2
answer = min(x,y)
print(answer)