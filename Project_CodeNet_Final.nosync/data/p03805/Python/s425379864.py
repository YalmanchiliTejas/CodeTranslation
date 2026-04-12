def solve(N, M, Es):
    al = {}
    for e in Es:
        al.setdefault(e[0], []).append(e[1])
        al.setdefault(e[1], []).append(e[0])

    ans = 0
    q = [(1, [1])]
    while len(q) > 0:
        current, history = q.pop()
        nexts = al[current] if current in al else []
        if len(history) == N:
            ans += 1
        for n in nexts:
            if n not in history:
                nhist = history[:]
                nhist.append(n)
                q.append((n, nhist))
    return ans


if __name__ == "__main__":
    N, M = map(int, input().split(" "))
    Es = []
    for _ in range(M):
        Es.append(tuple(map(int, input().split(" "))))
    print(solve(N, M, Es))
