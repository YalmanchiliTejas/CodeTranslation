inp = []
n = int(input())
ii = [int(f) for f in input().split()]
a = 1
for d in range(n-1):
    ff = ii[:d+1]
    ff.sort()
    if ff[d] <= ii[d+1]:
        a += 1
print(a)