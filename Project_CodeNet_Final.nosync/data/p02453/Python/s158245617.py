from bisect import bisect_left

n = int(input())
a = [*map(int, input().split())]
q = int(input())
while q:
    q -= 1
    k = int(input())
    print(bisect_left(a, k))
