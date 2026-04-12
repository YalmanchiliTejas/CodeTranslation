import sys

IMPOSSIBLE = 'Impossible'
POSSIBLE = 'Possible'

def solve():
    H, W = map(int, sys.stdin.readline().split())
    lines = list(map(lambda s: s.rstrip(), sys.stdin.readlines()))
    maxs = []
    mins = []
    for line in lines:
        m = -1
        for i, w in enumerate(line):
            if w == '#':
                m = i
        maxs.append(m)
        m = len(line)
        for i, w in reversed(list(enumerate(line))):
            if w == '#':
                m = i
        mins.append(m)

    for i, (min, max) in enumerate(zip(mins, maxs)):
        if '.' in lines[i][min:max+1]:
            return IMPOSSIBLE

    for min, max in zip(mins[1:], maxs):
        if min != max:
            return IMPOSSIBLE

    return POSSIBLE

print(solve())
