N,X,M = map(int,input().split())
R = [X]
dr = {}
for i in range(M):
    dr[i] = 0
m = min(N,M)
for i in range(m):
    r = R[-1]
    r = r**2%M
    if dr[r] == 1:
        break
    R.append(r)
    dr[r] = 1
for i in range(len(R)):
    if r == R[i]:
        break
a = 0
b = sum(R)
for j in range(i):
    a += R[j]
    b -= R[j]
n = len(R) - i
t = N - i
p = t // n
q = t % n
c = 0
for j in range(q):
    c += R[i+j]
ans = a + b*p + c
print(ans)