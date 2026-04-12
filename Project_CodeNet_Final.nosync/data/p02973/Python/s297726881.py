n = int(input())
a = [int(input()) for _ in range(n)]

import bisect
min_list = [-1]
for i in reversed(range(n)):
    if a[i] >= min_list[-1]:
        min_list.append(a[i])
    else:
        insert_index = bisect.bisect_right(min_list, a[i])
        min_list[insert_index] = a[i]
    # print(a[i], min_list)


print(len(min_list) - 1)
