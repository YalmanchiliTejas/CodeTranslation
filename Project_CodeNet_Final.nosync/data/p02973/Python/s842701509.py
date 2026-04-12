import collections, bisect

def resolve():

    n = int(input())
    ai = [int(input()) for _ in range(n)]

    d = collections.deque()

    for i in range(n):
        change_index = bisect.bisect_left(d, ai[i]) - 1
        if change_index == -1:
            d.appendleft(ai[i])
        else:
            d[change_index] = ai[i]

    print(len(d))
    
resolve()