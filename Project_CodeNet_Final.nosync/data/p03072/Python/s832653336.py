N = int(input())
H = list(map(int, input().split()))
count = 0
maxh = 0
for x in H:
    if x >= maxh:
        count += 1
        maxh = x
print(count)