from itertools import permutations, tee

N, M = map(int, input().split())
edges = set()

for _ in range(M):
    edges.add(tuple(map(int, input().split())))


def each_cons(iterable):
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)


def is_available(edge):
    return edge in edges or edge[::-1] in edges


cases = permutations(range(2, N + 1), N - 1)

count = 0

for numbers in cases:
    if all(map(is_available, each_cons((1,) + numbers))):
        count += 1


print(count)
