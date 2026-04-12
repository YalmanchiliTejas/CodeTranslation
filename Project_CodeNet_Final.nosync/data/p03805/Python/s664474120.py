import itertools

def main():
    n, m = map(int, input().split())
    g = set([tuple(map(int, input().split())) for _ in range(m)])

    ans = 0
    for path in itertools.permutations(list(range(1, n+1)), n):
        if path[0] != 1:
            continue
        flag = True
        for i in range(n-1):
            if ((path[i], path[i+1]) not in g) and ((path[i+1], path[i]) not in g):
                flag = False
        if flag is True:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()