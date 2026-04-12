input()
number_list = list(map(int, input().split()))
count = 0
for i in range(len(number_list)):
    max_height = 0
    for j in range(i):
        max_height = max(max_height, number_list[j])
    if(max_height <= number_list[i]):
        count += 1
print(count)