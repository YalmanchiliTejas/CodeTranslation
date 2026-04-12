n = int(input())
h = list(map(int,input().split()))
count = 0
maxh = 0
for i in h:
    if maxh <= i:
        maxh = i
        count += 1
print(count)