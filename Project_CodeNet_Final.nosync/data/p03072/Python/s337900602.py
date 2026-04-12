n = int(input())
h = map(int, input().split())
h = list(h)
mh = 0
count = 0
for i in range(n):
    if mh <= h[i]:
        mh = h[i]
        count += 1
print(count)