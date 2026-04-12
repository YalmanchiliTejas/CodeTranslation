from statistics import mean
import math

while True:
    n = int(input())
    if n == 0:
        break
    s = [int(input()) for _ in range(n)]
    s.remove(max(s))
    s.remove(min(s))
    print(math.floor(mean(s)))
