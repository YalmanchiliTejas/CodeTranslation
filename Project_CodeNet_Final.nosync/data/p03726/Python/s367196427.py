from sys import stdin
from itertools import repeat
def main():
    n = int(stdin.readline())
    dat = map(int, stdin.read().split(), repeat(10, 2 * n - 2))
    la = [None] * (n + 1)
    xt = [None] * (2 * n - 2)
    j = 0
    for i in xrange(n - 1):
        x = dat[j]
        y = dat[j+1]
        xt[j] = la[y]
        la[y] = j
        j += 1
        xt[j] = la[x]
        la[x] = j
        j += 1
    c = [None] * (n + 1)
    par = [0] * (n + 1)
    st = [1]
    pu = st.append
    po = st.pop
    f = 1
    c[0] = 0
    while st:
        x = po()
        if c[x] is None:
            c[x] = -1
            pu(x)
            y = la[x]
            while y is not None:
                z = dat[y]
                if c[z] is None:
                    par[z] = x
                    pu(z)
                y = xt[y]
        else:
            if c[x] == -1:
                if c[par[x]] == 0:
                    print "First"
                    return
                c[par[x]] = 0
                f = 0
            c[x] = 0
    print "Second"
main()
