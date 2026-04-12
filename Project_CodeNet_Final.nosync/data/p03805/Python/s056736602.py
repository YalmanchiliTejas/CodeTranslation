import collections

if __name__ == '__main__':
    n, m = map(int, input().split())
    
    ht = collections.defaultdict(list)
    for _ in range(m):
        a, b = [int(token) - 1 for token in input().split()]
        ht[a].append(b)
        ht[b].append(a)

    stack = [(0, 0)]
    cnt = 0
    while stack:
        position, history = stack.pop()
        if history | (1 << position) == 2 ** n - 1: cnt += 1

        for next_position in ht[position]:
            if history & (1 << next_position) == 0: stack.append((next_position, history | (1 << position)))
        
    print(cnt)


