n = int(input())
num_list = list(map(lambda x: int(x), input().split(" ")))
count = 0
for i, num in enumerate(num_list):
    if num >= max(num_list[:i+1]):
        count += 1
print(count)