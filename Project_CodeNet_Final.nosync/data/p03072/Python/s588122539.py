N = int(input())
H_list = list(map(int, input().split()))

higest = 0
count = 0
for h in H_list:
    if h >= higest:
        higest = h
        count += 1
print(count)

