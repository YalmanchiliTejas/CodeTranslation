length = int(input())
a = input().split()
count = 1
max_height = int(a[0])
for i in range(1,length):
    i_height = int(a[i])
    if (max_height <= i_height):
        count += 1
        max_height = i_height

print(count)