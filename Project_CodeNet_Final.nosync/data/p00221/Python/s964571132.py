def solve():
    from itertools import cycle
    from sys import stdin
    f_i = stdin
    m_i = map(lambda x: x.rstrip(), f_i)
    
    while True:
        m, n = map(int, next(m_i).split())
        if m == 0:
            break
        
        player = list(range(1, m + 1))
        ans = ('FizzBuzz' if i % 15 == 0 else 'Fizz' if i % 3 == 0 else
               'Buzz' if i % 5 == 0 else str(i) for i in range(1, n + 1))
        
        while len(player) > 1:
            for p, a in zip(cycle(player), ans):
                n -= 1
                if next(m_i) != a:
                    break
            else:
                break
            idx = player.index(p)
            player = player[idx+1:] + player[:idx]
        while n:
            next(m_i)
            n -= 1
        player.sort()
        print(*player)

solve()
