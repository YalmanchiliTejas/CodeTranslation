N = int(input())
H_list = list(map(int, input().split()))

counter = 0
for i in range(N):
    if i == 0:
        counter += 1
    if i > 0:
        max_before_i = max(H_list[:i+1])
        if max_before_i <= H_list[i]:
            counter += 1

print(counter)