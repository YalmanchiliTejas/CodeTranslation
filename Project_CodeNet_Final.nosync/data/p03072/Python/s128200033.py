_ = input()
H_list = [int(n) for n in input().split()]

highest = 0
count = 0

for h in H_list:
    if h >= highest:
        count += 1
        highest = h

print(count)
