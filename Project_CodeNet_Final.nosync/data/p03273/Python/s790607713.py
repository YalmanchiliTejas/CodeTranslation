H, W = map(int, input().split())

remove = "." * W
A = []
for i in range(H):
    a = input()
    if a != remove:
        A.append(list(a))

remove_list = []
# print(A)
for i in range(W):
    if A[0][i] == ".":
        aa = A[0][i]
        flag = 0
        for a in A:
            if aa != a[i]:
                flag = 1
                break
        if flag == 0:
            remove_list.append(i)

# print(remove_list)

for a in A:
    print_list = []
    for idx, a_ in enumerate(a):
        if idx not in remove_list:
            print_list.append(a_)
    print("".join(print_list))