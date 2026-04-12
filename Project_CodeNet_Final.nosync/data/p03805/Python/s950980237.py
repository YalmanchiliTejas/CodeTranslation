# from log import logger

N, M = map(int, input().split())
key_value = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    key_value[a].append(b)
    key_value[b].append(a)

# logger.info('key_value: {}\n'.format(key_value))

closed_list = [False] * N
closed_list[0] = True
cnt = 0


def dfs(target):
    global cnt
    # logger.info('key_value[target]: {}'.format(key_value[target]))
    if all(closed_list):
        cnt += 1
        return
    for node in key_value[target]:
        # logger.info('node: {}'.format(node))
        # 探索済みでない場合
        if closed_list[node] is False:
            closed_list[node] = True
            dfs(node)
            closed_list[node] = False
        # logger.info('closed_list: {}\n'.format(closed_list))
    return


dfs(0)
print(cnt)
