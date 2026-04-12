n = int(input())
h_list = list(map(int, input().split()))
highest = 0
count = 0

for i in range(n):
    if highest <= h_list[i]:
        count += 1
        highest = h_list[i]

print(count)
