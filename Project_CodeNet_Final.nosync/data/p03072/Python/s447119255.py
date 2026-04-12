n = int(input())
src = list(map(int, input().split()))
m = src[0]
count = 0
for s in src:
    if s >= m:
        count += 1
        m = s
print(count)