N = int(input())
H = list(map(int,input().split()))

hmax = 0
count = 0
for h in H:
    if h >= hmax:
        hmax = h
        count += 1

print(count)