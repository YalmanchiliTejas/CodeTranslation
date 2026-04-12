N = input()
HH = [int(i) for i in input().split()]
Hmax = -1
k = 0
for H in HH:
    if H >= Hmax:
        k += 1
        Hmax = H
print(k)