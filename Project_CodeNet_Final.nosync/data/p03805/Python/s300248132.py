import sys
import copy

input = sys.stdin.readline

A = None


def dfs(i, v):
    global A
    v.add(i)

    ans = 0
    for j in A[i]:
        if j not in v:
            v2 = copy.deepcopy(v)
            ans += dfs(j, v2)

    if len(A) - 1 == len(v):
        ans += 1
    return ans


def main():
    global A
    N, M = [int(x) for x in input().split()]
    A = [[] for j in range(N + 1)]
    for _ in range(M):
        a, b = [int(x) for x in input().split()]
        A[a].append(b)
        A[b].append(a)

    print(dfs(1, set()))


if __name__ == '__main__':
    main()
