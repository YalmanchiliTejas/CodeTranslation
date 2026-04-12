n = int(input())
h = list(map(int, input().split()))
mx = 0
c = 0
for hi in h:
    if mx <= hi:
        c += 1
        mx = hi
print(c)
