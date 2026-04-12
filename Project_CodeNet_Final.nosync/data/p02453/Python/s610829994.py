import bisect
input(); A = list(map(int, input().split()))
for _ in [0]*int(input()):
    print(bisect.bisect_left(A, int(input())))
