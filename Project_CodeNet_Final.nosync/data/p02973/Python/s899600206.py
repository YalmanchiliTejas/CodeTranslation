from bisect import bisect_right
n = int(input())
a_list = []
for i in range(n):
    a = int(input())
    a_list.append(a)
a_list.reverse()
l_list = [a_list[0]]
for i in range(1, n):
    a = a_list[i]
    if l_list[-1] <= a:
        l_list.append(a)
    else:
        index = bisect_right(l_list, a)
        l_list[index] = a
print(len(l_list))