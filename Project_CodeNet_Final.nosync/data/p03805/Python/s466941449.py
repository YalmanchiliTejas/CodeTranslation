import sys

n, m = map(int, input().split())

array = [[int(x) for x in input().split()] for x in range(m)]

if m == 0:
    print(0)
    sys.exit()

adj_array = [[] for x in range(n + 1)]
res_array = [True] + [False for x in range(n)]
for item in array:
    adj_array[item[0]].append(item[1])
    adj_array[item[1]].append(item[0])


def dfs(n, res_array, res):
    res_array[n] = True
    if False not in res_array:
        return res+1
    else:
        for next in adj_array[n]:
            if not res_array[next]:
                res = dfs(next, list(res_array), res)
    return res


res = 0
res_array[1] = True
print(dfs(1, res_array, res))
