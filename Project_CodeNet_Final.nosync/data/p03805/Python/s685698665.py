def num_paths(trail, num_all_nodes, edges):
    if len(trail) == num_all_nodes:
        return 1

    count = 0
    for dest in edges[trail[len(trail)-1]]:
        if dest in trail:
            continue
        count += num_paths(trail + [dest], num_all_nodes, edges)
    return count


def main():
    n, m = [int(x) for x in input().split()]
    edges = [set() for i in range(n)]
    for i in range(m):
        a, b = [int(x) - 1 for x in input().split()]
        edges[a].add(b)
        edges[b].add(a)
    print(num_paths([0], n, edges))


main()
