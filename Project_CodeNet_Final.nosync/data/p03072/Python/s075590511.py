n = int(input())
height_list = [int(i) for i in input().split(" ")]
is_see_count = 0
for i in range(n):
    if n == 0:
        is_see_count += 1
    else:
        height = height_list[i]
        for j in range(i):
            if not height >= height_list[j]:
                break
        else:
            is_see_count += 1
print(is_see_count)
