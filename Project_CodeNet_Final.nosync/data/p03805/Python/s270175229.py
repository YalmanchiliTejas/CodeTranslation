from itertools import permutations

def check(adj, pat):
    pos = 1
    for p in pat:
        if p not in adj[pos]:
            return 0
        else:
            pos = p
    return 1

def main():
    n, m = [int(i) for i in input().split()]
    adj = {i+1:[] for i in range(n)}
    for _ in range(m):
        a, b = [int(i) for i in input().split()]
        adj[a].append(b)
        adj[b].append(a)

    res = 0
    for t in permutations(range(2, n+1)):
        res += check(adj, t)
    print(res)

if __name__ == '__main__':
    main()

