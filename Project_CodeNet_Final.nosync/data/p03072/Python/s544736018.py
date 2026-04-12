mount_count = input()
mount_heights = input()
mount_heights_list = mount_heights.split()
count = 0
max_height = int(mount_heights_list[0])
for mount_height in mount_heights_list:
    if max_height <= int(mount_height):
        max_height = int(mount_height)
        count += 1
print(count)

