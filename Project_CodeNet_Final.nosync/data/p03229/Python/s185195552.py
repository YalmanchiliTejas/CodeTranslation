def calc_ans(max_list):
    ans = 0
    for i in range(n - 1):
        ans += abs(max_list[i+1] - max_list[i])
    return ans

n = int(input())
a = [int(input()) for i in range(n)]

a.sort()
if n % 2 == 0:
    max_list = []
    mean = n // 2
    list1 = a[mean:]
    list2 = a[:mean]
    for i in range(mean):
        max_list.append(list1[i])
        max_list.append(list2[i])
    ans = calc_ans(max_list)
else:
    max_list = []
    mean = n // 2
    list1 = a[mean:]
    list2 = a[:mean]
    list1[1], list1[-1] = list1[-1], list1[1]
    for i in range(mean):
        max_list.append(list1[i])
        max_list.append(list2[i])
    max_list.append(list1[-1])
    ans = calc_ans(max_list)

    max_list = []
    mean = n // 2 + 1
    list1 = a[:mean]
    list2 = a[mean:]
    list1[0], list1[-2] = list1[-2], list1[0]
    for i in range(mean - 1):
        max_list.append(list1[i])
        max_list.append(list2[i])
    max_list.append(list1[-1])
    ans = max(ans, calc_ans(max_list))

print(ans)