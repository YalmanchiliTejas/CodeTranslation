from itertools import chain
h, w = map(int, input().split())
As = list(chain.from_iterable([list(input()) for i in range(h)]))
print("Possible" if As.count("#") == h + w - 1 else "Impossible")