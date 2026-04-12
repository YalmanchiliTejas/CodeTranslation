n, m = map(int, input().split())
array = [[int(x) for x in input().split()] for y in range(m)]
modify = [[] for x in range(n + 1)]

for value1, value2 in array:
    modify[value1].append(value2)
    modify[value2].append(value1)


def solver(start, array, visited, cnt):
    if visited[start]:
        return cnt
    else:
        visited[start] = True

    for i in array[start]:
        if len(set(visited)) == 1:
            return cnt+1
        else:
            cnt = solver(i, array, list(visited), cnt)

    return cnt



start = modify[1]
res = 0
for i in start:
    visited = [False if x != 0 and x != 1 else True for x in range(n + 1)]
    res += solver(i, modify, visited, 0)

print(res)
