from itertools import accumulate
from operator import eq
N = int(input())
H = list(map(int, input().split()))
print(sum(map(eq, H, accumulate(H, max))))