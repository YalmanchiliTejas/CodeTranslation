N = int(input())
H = [int(i) for i in input().split()]

count = 0
pre_max = 0
for h in H:
    if h >= pre_max:
        count += 1
        pre_max = h
print(count)