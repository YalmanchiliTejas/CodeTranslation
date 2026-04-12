def solve(N, X, M):
    seen = set()
    front = [X]
    cycle = []
    for i in range(N - 1):
        x = (front[-1] * front[-1]) % M
        if x in seen:  # seen can't be more than M since x is < M
            index = front.index(x)
            front, cycle = front[:index], front[index:]
            break
        front.append(x)
        seen.add(x)
    if N <= len(front):
        return sum(front[:N])

    if N <= len(front) + len(cycle):
        return sum(front) + sum(cycle[: N - len(front)])

    q, r = divmod(N - len(front), len(cycle))

    if False:
        A = [pow(X, 2 ** i, M) for i in range(N)]
        B = front + cycle * q + cycle[:r]
        print(A, B)
        assert A == B
    return sum(front) + sum(cycle) * q + sum(cycle[:r])


N, X, M = [int(x) for x in input().split()]
print(solve(N, X, M))
