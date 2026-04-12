# coding=utf-8


def push(piles: list, pile_number: str, color: str) -> list:
    piles[int(pile_number)-1].append(color)
    return piles


def pile_pop(piles: list, pile_number: str) -> list:
    removed = piles[int(pile_number)-1].pop()
    print(removed)
    return piles


def move(piles: list, pile_number1: str, pile_number2: str) -> list:
    moved = piles[int(pile_number1)-1].pop()
    piles[int(pile_number2)-1].append(moved)
    return piles


if __name__ == '__main__':
    n = int(input())
    pile_list = [[] for i in range(n)]
    while True:
        order = input().split()
        if order[0] == 'quit':
            break
        elif order[0] == 'push':
            pile_list = push(pile_list[:], order[1], order[2])
        elif order[0] == 'pop':
            pile_list = pile_pop(pile_list[:], order[1])
        elif order[0] == 'move':
            pile_list = move(pile_list[:], order[1], order[2])