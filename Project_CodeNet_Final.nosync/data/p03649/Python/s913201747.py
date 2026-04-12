N = int(input())
A = list(map(int, input().split()))


def is_possible(C):
    res = 0
    for x in A:
        if x+C - N >= 0:
            res += (x+ C - N)//(N+1) + 1
    #print(res,C)
    return int(res <= C)

l = 0  # impossible
r = 10**30  # possible
is_possible(1234567894848)
while r - l > 1:
    M = (l+r)//2
    if is_possible(M)>0:
        r = M
    else:
        l = M
for i in range(10**5,-1,-1):
    if is_possible(r -i):
        print(r-i)
        break