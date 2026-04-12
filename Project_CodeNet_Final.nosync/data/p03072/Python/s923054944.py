N = int(input())
H = list(map(int,input().split()))
count = 0
highest = 0
for h in H:
    if h >= highest:
        highest = h
        count +=1

print(count)