import sys
import math
from collections import deque

sys.setrecursionlimit(4100000)


def inputs(num_of_input):
    ins = [input() for i in range(num_of_input)]
    return ins


def solve(inputs):
    H = string_to_int(inputs[0])

    max_heigh = 0
    count = 0
    for h in H:
        if h >= max_heigh:
            max_heigh = h
            count += 1
    return count


def string_to_int(string):
    return list(map(lambda x: int(x), string.split()))


if __name__ == "__main__":
    input()
    ret = solve(inputs(1))
    print(ret)
