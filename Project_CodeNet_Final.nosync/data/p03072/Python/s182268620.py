n = int(input())
h = [int(i) for i in input().split()]

s = 1
mount_max = -1
for i in range(1,n):
    mount_max = max(mount_max, h[i-1])
    if mount_max <= h[i]:
        s += 1
print(s)
