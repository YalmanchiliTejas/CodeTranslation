def main():
    N, M = (int(i) for i in input().split())
    G = [set() for _ in range(N+1)]
    for m in range(M):
        a, b = (int(i) for i in input().split())
        G[a].add(b)
        G[b].add(a)
    
    from itertools import permutations
    trial_path = (p for p in permutations(range(2,N+1),N-1))

    def exist_path(st,path):
        for p in path:
            if p in G[st]: st = p
            else: return False
        else: 
            return True

    ans = 0
    for path in trial_path:
        if exist_path(1,path):
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()