_ = int(input())
h_list = list(map(int, input().split()))
max = 0
count = 0

for h in h_list:
    if h >= max:
        max = h
        count += 1

print(count) 
