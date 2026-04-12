N = int(input())
H = list(map(int, input().split()))
m = 0
count = 0
for h in H:
    if h >= m:
        count += 1
        m = h
print(count)
