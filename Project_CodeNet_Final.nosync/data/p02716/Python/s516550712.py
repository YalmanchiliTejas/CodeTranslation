import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int, readline().split()))

INF = 10**18
limit = 4
S = (2*limit+3)
dpb = [-INF]*S
dpw = [-INF]*S
dpw[0] = 0
for i in range(N):
    a = A[i]
    dpb2 = [-INF]*S
    dpw2 = [-INF]*S
    for j in range(-limit, limit):
        if -limit <= j - 1 < limit:
            dpw2[j-1] = max(dpw2[j-1], dpb[j], dpw[j])
            dpb2[j-1] = max(dpb2[j-1], dpb[j], dpw[j])
        if -limit <= j + 1 < limit:
            dpb2[j+1] = max(dpb2[j+1], dpw[j]+a)
    dpw = dpw2[:]
    dpb = dpb2[:]

idx = N//2*2 - N
print(max(dpw[idx], dpb[idx]))
    