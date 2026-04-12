N = int(input())
H_list = input().split()
H_list_i = [int(h) for h in H_list]

count = 1
for k in range(1, N):
    if H_list_i[k - 1] <= H_list_i[k]:
        s = 0
        for l in range(k):
            if H_list_i[k] >= H_list_i[l]:
                s = s + 1
            else:
                break

        if s == k:
            count = count + 1
        s = 0
print(count)
