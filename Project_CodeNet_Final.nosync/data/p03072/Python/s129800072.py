N = int(input())
H = list(map(int, input().split()))
pre_h = 0
count = 0
for h in H:
    if h >= pre_h:
        count += 1
        pre_h = h
print(count)
