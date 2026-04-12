N, M = map(int, input().split())

dict_path = {}
path = []

for i in range(M):
    a, b = input().split()
    path.append((a, b))
    path.append((b, a))

for i in range(1, N+1):
    tmp = []
    for j in path:
        a, b = j
        if a == str(i):
            tmp.append(b)
    dict_path[str(i)] = tmp

stack = ['1']
root = ['1']

ans = 0
while stack:
    path = stack.pop(-1)
    now = path[-1]
    for i in dict_path[now]:
        tmp = path
        if i not in path:
            tmp += i
            if tmp not in root:
                stack.append(tmp)
                root.append(tmp)
                if len(tmp) == N:
                    ans += 1

print(ans)
