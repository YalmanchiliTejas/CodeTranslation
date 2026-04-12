import math
while True:
    n = int(input())
    if n == 0:
        break
    s = []
    for i in range(n):
        s.append(int(input()))
    print(math.floor((sum(s) - min(s) - max(s)) / (n - 2)))