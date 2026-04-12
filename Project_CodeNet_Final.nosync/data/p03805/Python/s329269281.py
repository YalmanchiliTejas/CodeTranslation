from sys import stdin
from itertools import permutations
from collections import Counter


def main():
    _in = [_.rstrip() for _ in stdin.readlines()]
    N, M = list(map(int,_in[0].split(' ')))  # type:list(int)
    graph = []
    for i in range(M):
        _ = list(map(int,_in[i+1].split(' ')))  # type:list(int)
        graph.append(_)
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    con = [[] for i in range(N)]
    for a,b in graph:
        a -= 1
        b -= 1
        con[a].append(b)
        con[b].append(a)
    for i, _ in enumerate(con):
        con[i] = Counter(con[i])

    cnt = 0
    for cand in permutations(range(1,N)):
        _cand = (0,)+cand
        mult = 1
        for v,nv in zip(_cand[:-1],_cand[1:]):
            try:
                mult *= con[v][nv]
            except:
                mult = 0
                break
        cnt += mult
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(cnt)

if __name__ == "__main__":
    main()
