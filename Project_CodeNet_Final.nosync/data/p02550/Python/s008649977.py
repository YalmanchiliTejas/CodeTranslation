from sys import stdin

input = stdin.readline
MOD = 998244353


def solve():
    N,X,M = map(int,input().split())
    cur = X
    res = [0]
    d = {}

    for i in range(N):
        res.append(cur+res[-1])
        if d.get(cur,-1) != -1:
            #d[cur]----i cycle
            pos = d[cur]
            m,r = divmod(N - pos,i-pos)
            s  = (res[i] - res[pos])*m + res[pos+r]
            print(s)
            return
        d[cur] = i
        cur =  (cur**2)%M

    print(res[-1])


if __name__ == '__main__':
    solve()
