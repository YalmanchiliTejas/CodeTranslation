n = int(input())
h = list(map(int,input().split()))

maxh = h[0]
count = 1

for i in range(1,len(h)):
    if maxh <= h[i]:
        maxh = h[i]
        count = count + 1

print(count)
