def slove():
    import sys
    import collections
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    d = collections.defaultdict(list)
    for i in range(n):
        t = collections.Counter(str(input().rstrip('\n')))
        for k, v in t.items():
            d[k] += [v]
    ans = []
    for k, v in d.items():
        if len(v) == n:
            for i in range(min(v)):
                ans.append(k)
    ans.sort()
    print("".join(ans))


if __name__ == '__main__':
    slove()
