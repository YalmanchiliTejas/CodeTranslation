from itertools import product

N = int(raw_input())
ox = [1 if c == 'o' else 0 for c in raw_input()]

SHEEP, WOLF = 0, 1
a = [None] * N

for s1, s2 in product([SHEEP, WOLF], repeat=2):
    a[0], a[1] = s1, s2
    for i in xrange(2, N):
        a[i] = 1 - ((ox[i - 1] ^ a[i - 1]) ^ a[i - 2])

    ok = True
    for i in xrange(N):
        same = 1 if a[i - 1] == a[i + 1 - N] else 0
        if ox[i] + a[i] + same in (1, 3):
            ok = False
            break
    if ok:
        print ''.join('SW'[a[i]] for i in xrange(N))
        break
else:
    print -1