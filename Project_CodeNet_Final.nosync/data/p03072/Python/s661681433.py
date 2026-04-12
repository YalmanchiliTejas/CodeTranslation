N = int(input())
mount_list = list(map(int, input().split()))
max_hight = 0
ryokan = 0
for i in range(len(mount_list)):
    if max_hight<= mount_list[i]:
        max_hight = mount_list[i]
        ryokan+=1

print(ryokan)