def resolve():
    N, M = list(map(int, input().split()))
    A = [list(map(int, input().split())) for i in range(M)]
    cnt = 0
    import itertools
    L = list(itertools.permutations(range(2, N+1)))
    for route in L:
        src = 1
        for point in route:
            dst = point
            if not ([src, dst] in A or [dst, src] in A):
                break
            src = dst
        else:
            cnt += 1
    print(cnt)

if '__main__' == __name__:
    resolve()