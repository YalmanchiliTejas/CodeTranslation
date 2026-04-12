from itertools import permutations 
n, m = map(int, input().split())

M = [[0]*n for _ in range(n)]
for _ in range(m):
    a,b = map(int, input().split())
    M[a-1][b-1] = 1
    M[b-1][a-1] = 1

cnt = 0
for per in permutations(range(n)):
    Pth = True
    for i in range(n-1):
        if M[per[i]][per[i+1]] != 1 or per[0]!=0:
            Pth = False
            break
    if Pth:
        cnt += 1
print(cnt)