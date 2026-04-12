import math
N = int(input())
As = list(map(int, input().split()))

def check():
    return all([a <= N-1 for a in As])

ans = 0
while not check():
    n = 0
    for i in range(N):
        a = As[i]
        t = a // N
        n += t
        As[i] -= t * (N+1)
    for i in range(N):
        As[i] += n
    ans += n
print(ans)
