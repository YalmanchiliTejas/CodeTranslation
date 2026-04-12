# encoding: utf-8
N, X = map(int, input().split())

def count(level, pos):
    L_child = 2 ** ((level - 1) + 2) - 3
    P_child = 2 ** ((level - 1) + 1) - 1
    # solved
    if pos == 0: return 0 if level > 0 else 1
    elif pos < L_child + 1: return count(level - 1, pos - 1)
    elif pos == L_child + 1: return P_child + 1
    elif L_child + 1 < pos < 2 * (L_child + 1):
        return P_child + 1 + count(level - 1, pos - (L_child + 2))
    else: return 2 * P_child + 1

print(count(N, X - 1))