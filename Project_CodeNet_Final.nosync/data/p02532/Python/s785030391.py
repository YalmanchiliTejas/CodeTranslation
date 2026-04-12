from __future__ import print_function
import sys

num_stack = int(sys.stdin.readline())
stacks = [[] for n in xrange(num_stack)]
for line in sys.stdin:
    if line.startswith('quit'):
        break
    if line.startswith('push'):
        p, c = line.split()[1:]
        stacks[int(p) - 1].append(c)
    elif line.startswith('pop'):
        p = line.split()[1]
        print(stacks[int(p) - 1].pop())
    elif line.startswith('move'):
        p1, p2 = line.split()[1:]
        stacks[int(p2) - 1].append(stacks[int(p1) - 1].pop())