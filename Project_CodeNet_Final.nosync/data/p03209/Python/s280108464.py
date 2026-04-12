# from typing import NamedTuple

# class Burger(NamedTuple):
#     total: int
#     patty: int

from collections import namedtuple

def solve(n, x, burgers, total_eaten, patty_eaten):
    if n == 0:
        total_eaten += 1
        patty_eaten += 1
        return total_eaten, patty_eaten

    # try to eat the entire current level
    tmp_total = burgers[n].total
    tmp_patty = burgers[n].patty
    if total_eaten + tmp_total < x:
        return total_eaten + tmp_total, patty_eaten + tmp_patty

    # eat the lower bun
    total_eaten += 1
    if total_eaten == x:
        return total_eaten, patty_eaten

    # eat the lower n - 1 th burger
    total_eaten, patty_eaten = solve(n - 1, x, burgers, total_eaten, patty_eaten)
    if total_eaten == x:
        return total_eaten, patty_eaten

    # eat the middle patty
    total_eaten += 1
    patty_eaten += 1
    if total_eaten == x:
        return total_eaten, patty_eaten

    # eat the upper n - 1 th burger
    total_eaten, patty_eaten = solve(n - 1, x, burgers, total_eaten, patty_eaten)
    if total_eaten == x:
        return total_eaten, patty_eaten

    # eat the upper bun
    # the program should not reach the current line because this mean n th burger is eaten (= eat the entire current level)
    total_eaten += 1
    return total_eaten, patty_eaten

def main():
    N, X = map(int, input().split())
    Burger = namedtuple('Burger', ['total', 'patty'])
    burgers = [Burger(total=1, patty=1)]
    for i in range(N):
        total = burgers[i].total
        patty = burgers[i].patty
        burger = Burger(total=3 + total*2, patty=1 + 2*patty)
        burgers.append(burger)
    # print(burgers)
    total_eaten, patty_eaten = 0, 0
    total_eaten, patty_eaten = solve(N, X, burgers, total_eaten, patty_eaten)
    print(patty_eaten)

if __name__ == '__main__':
    main()
