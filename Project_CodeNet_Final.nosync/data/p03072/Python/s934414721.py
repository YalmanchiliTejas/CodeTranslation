from itertools import accumulate

n = int(input())
h = list(map(int, input().split()))

max_h = list(accumulate(h, max))


print(sum([1 for h, m in zip(h, max_h) if h == m]))