N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

l = 0
r = N-1
p = []
ans = 0
while l < r:
    p.append(A[r])
    p.append(A[l])
    r -= 1
    l += 1
if N % 2 == 1:
    p.append(A[r])

p.append(p[0])
q = []
for i in range(len(p)-1):
    q.append(abs(p[i] - p[i+1]))

ans = sum(q)-min(q)

l = 0
r = N-1
p = []
while l < r:
    p.append(A[l])
    p.append(A[r])
    r -= 1
    l += 1
if N % 2 == 1:
    p.append(A[r])

p.append(p[0])
q = []
for i in range(len(p)-1):
    q.append(abs(p[i] - p[i+1]))

print(max(ans,sum(q)-min(q)))