n = int(input())
nums_str = input()
nums_str_arr = nums_str.split(' ')

max_height = 0
count = 0

for i in range(n):
    num = int(nums_str_arr[i])
    if max_height <= num:
        count += 1
        max_height = num

print(count)
