import sys

inputs = [row.split() for row in sys.stdin.readlines()]

mount_list = inputs[1]
mount_list = [int(height) for height in mount_list]

result_cnt = 0
old_max_height = mount_list[0]
for height in mount_list:
    if old_max_height <= height:
        result_cnt+=1
        old_max_height = max(old_max_height, height)
print(result_cnt)

