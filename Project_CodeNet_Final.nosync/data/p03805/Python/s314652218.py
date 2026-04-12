from itertools import permutations
def main():
    n, m = map(int, input().split())
    path = []
    for _ in range(m):
        path.append(tuple(map(int, input().split())))

    nodes = [i for i in range(2, n + 1)]
    routes = permutations(nodes, n-1)

    r = 0
    for route in routes:
        route = list(route)
        route.insert(0,1)
        for i1 in range(n-1):
            if (route[i1], route[i1+1]) not in path:
                if (route[i1+1], route[i1]) not in path:
                    break
        else:
            r += 1
    print(r)

if __name__ == '__main__':
    main()
