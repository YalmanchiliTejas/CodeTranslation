# Problem B - ISU

# input
x, y, z = map(int, input().split())

# initialization
chair_len = x - 2 * z
max_count = 0

# count
i = 0
while True:
    if i%2==0:
        if chair_len-y<0:
            break
        max_count += 1
        chair_len -= y
    else:
        if chair_len-z<0:
            break
        chair_len -= z

    i += 1

print(max_count)
