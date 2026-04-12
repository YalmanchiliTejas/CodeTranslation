N = int(input())
H = list(map(int, input().split()))
maxh = H[0]
count = 1
for h in H[1:]:
    if h >= maxh:
        count+=1
        maxh = h
print(count)