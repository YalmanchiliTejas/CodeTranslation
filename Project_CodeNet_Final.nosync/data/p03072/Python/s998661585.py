n = int(input())
h_list = list(map(int,input().split()))
count = 0
max_num = 0
for h in h_list:
    if max_num <= h:
        count += 1
        max_num = h
print(count)