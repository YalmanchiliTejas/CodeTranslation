def slove():
    import sys
    import bisect
    import collections
    import copy
    import fractions
    import heapq
    input = sys.stdin.readline
    n, m = list(map(int, input().rstrip('\n').split()))
    d = collections.defaultdict(list)
    for i in range(m):
        a, b = list(map(int, input().rstrip('\n').split()))
        d[a-1] += [b-1]
        d[b-1] += [a-1]

    ql = collections.deque()
    ql.append([0, [0]])
    cnt = 0
    while True:
        if len(ql) != 0:
            qp, ls = ql.popleft()
            for v in d[qp]:
                if v not in ls:
                    tls = copy.deepcopy(ls)
                    tls.append(v)
                    if len(tls) < n:
                        ql.append([v, tls])
                    else:
                        cnt += 1
        else:
            break
    print(cnt)


if __name__ == '__main__':
    slove()
