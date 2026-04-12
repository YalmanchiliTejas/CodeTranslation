import itertools

def sonzai(path, start, goal):
    for i in path:
        if start in i:
            if start > goal:
                if i[0] == goal:
                    return True
            else:
                if i[1] == goal:
                    return True
    return False

n, m = map(int, input().split())
path = []
for i in range(m):
    a, b = map(int, input().split())
    path.append([a, b])
ans = 0
for i in itertools.permutations(range(2, n + 1)):
    if not sonzai(path, 1, i[0]):
        continue
    for j in range(n - 1):
        if j == n - 2:
            ans += 1
            break
        if not sonzai(path, i[j], i[j + 1]):
            break
print(ans)