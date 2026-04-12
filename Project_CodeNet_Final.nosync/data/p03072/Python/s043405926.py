n = int(input())
h_list = list(map(int, input().split()))

max_h=0
count=0
for i in h_list:
    if max_h <= i:
        max_h = i
        count += 1

print(count)