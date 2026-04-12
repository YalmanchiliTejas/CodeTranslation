N,X,M = map(int,input().split())
A = [0]*M
S = 0
r = X % M
A[r] = 1
d = 0
I = 0
for i in range(1,M+1):
    r = (r*r) % M
    if A[r] == 0:
        A[r] = i+1
    else:
        I = A[r]
        j = i+1
        d = j-I
        break
r = X
for i in range(I):
    S += r
    r = (r*r) % M
if d != 0:
    t,u = (N-I)//d,(N-I)%d
    s = 0
    for i in range(d):
        s += r
        r = (r*r) % M
    S += s*t
    for i in range(u):
        S += r
        r = (r*r) % M
print(S)