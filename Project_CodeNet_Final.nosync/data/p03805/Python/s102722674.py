def slove():
    import sys
    import collections
    import copy
    input = sys.stdin.readline
    n, m = list(map(int, input().rstrip('\n').split()))
    ab = collections.defaultdict(list)
    for i in range(m):
        a, b = list(map(int, input().rstrip('\n').split()))
        ab[a] += [b]
        ab[b] += [a]
    td = collections.defaultdict(list)
    td[1]
    q = [[1, td]]
    ans = []
    while True:
        if len(q) != 0:
            p, d = q.pop()
            if len(d) != n:
                for v in ab[p]:
                    if v not in d:
                        td = copy.deepcopy(d)
                        td[v]
                        q.append([v, td])
            else:
                ans.append([d])
        else:
            print(len(ans))
            exit()


if __name__ == '__main__':
    slove()
