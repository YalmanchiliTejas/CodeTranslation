import itertools
N, M = map(int, input().split())

root_dict = {str(i) : [] for i in range(1, N+1)}
for i in range(M):
    root = input().split()
    root_dict[root[0]] = root_dict[root[0]] + [root[1]]
    root_dict[root[1]] = root_dict[root[1]] + [root[0]]
result = 0
numbers = [str(i) for i in range(2, N+1)]
numbers = ''.join(numbers)

for order in itertools.permutations(numbers, N-1):#1以降の順列
    prev_num = "1"
    flag = True
    for num in order:
        if num not in root_dict[prev_num]:
            flag = False
            break
        prev_num = num
    if flag:
        result += 1

print(result)