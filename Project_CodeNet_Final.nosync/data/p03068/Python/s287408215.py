N = int(input())
list1 = [i for i in input()]
K = int(input())

list2 = []
for j in list1:
    if j == list1[K-1]:
        list2.append(list1[K-1])
    else:
        list2.append("*")


ans = ''.join(list2)
print(ans)