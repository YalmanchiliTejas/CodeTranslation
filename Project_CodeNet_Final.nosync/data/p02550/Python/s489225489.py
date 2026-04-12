import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]

    N,X,M = LI()

    d = [0] * (M+1)
    t = [0] * (M+1)

    aa = X
    i = 0
    s = 0
    while d[aa] == 0:
        i += 1
        d[aa] = i
        s += aa
        t[i] = s
        aa = (aa * aa) % M

    ans = 0
    if N <= i:
        ans = t[N]

    else:
        m = i - d[aa] + 1
        r = d[aa] - 1 + ((N - (d[aa]-1)) % m)

        ans = t[r]
        ans += (t[i] - t[d[aa]-1]) * ((N-(d[aa]-1)) // m)


    print(ans)


if __name__ == '__main__':
    main()