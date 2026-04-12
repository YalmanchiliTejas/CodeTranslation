from collections import defaultdict

N = int(input())
A = [int(input()) for i in range(N)]
d = defaultdict(lambda: [])
for i,a in enumerate(A):
    d[a].append(i)
B = [None for i in range(N)]
for i,k in enumerate(sorted(d.keys())):
    for j in d[k]:
        B[j] = i

bit = [0] * (N+2)
def bit_add(a,w):
    x = a
    while x <= N+1:
        bit[x] += w
        x += (x & -x)

def bit_sum(a):
    x = a
    ret = 0
    while x > 0:
        ret += bit[x]
        x -= (x & -x)
    return ret

for a in B:
    a += 2

    s = bit_sum(a)
    bit_add(a,1)
    if s and bit_sum(a-1):
        t = bit_sum(a-1)
        ok = a-1
        ng = 0
        while ok-ng > 1:
            m = (ok+ng)//2
            if bit_sum(m) == t:
                ok = m
            else:
                ng = m
        bit_add(ok,-1)

    # for i in range(N+1):
    #     print(i+1, bit_sum(i+1))

print(bit_sum(N+1))