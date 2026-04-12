mnt = int(input())
list_of_heght = [int(i) for i in input().split()]
# 海を見れる旅館の数
num_of_hotel = 1
idx =1
for i in list_of_heght[1:]:
    tmp = list_of_heght[0:idx]
    if max(tmp) <= i:
        num_of_hotel += 1
    idx += 1
print(num_of_hotel)