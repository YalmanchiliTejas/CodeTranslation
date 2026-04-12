N = int(input())
H_list = list(map(int, input().split()))
result = 1
level = H_list.pop(0)
for H in H_list:
    if level <= H:
        result += 1
        level = H
print(result)