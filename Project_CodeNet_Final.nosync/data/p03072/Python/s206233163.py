N = int(input())
max1 = 0
count = 0
H_list = list(map(int, input().split()))

for i in H_list:
    if max1 <= i:
        max1 = i
        count += 1

print(count)
    