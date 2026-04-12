N = int(input())
H = list(map(int, input().split()))

res = 1

for i in range(1, N):
    part_list = H[:i+1]
    tf_list = [H[i] < x for x in part_list]
    if sum(tf_list) == 0:
        res += 1

print(res)
