from itertools import *

N = int(input())
Hn = list(map(int, input().split()))

print(1 + sum([
    int(all([ hj <= h for hj in islice(Hn, i+1) ]))
    for i, h in enumerate(Hn[1:])
]))
