n = int(input())
h_l = list(map(int, input().split()))
max_h = 0
count = 0
for h in h_l:
    if h >= max_h:
        count += 1
        max_h = h
        
print(count)