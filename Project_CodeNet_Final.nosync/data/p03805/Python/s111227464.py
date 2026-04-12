#-*-coding:utf-8-*-
from collections import deque

ans = 0

def dfs(v, n, used, linked_list):
    global ans
    if len(used) == n:
        ans += 1
        return
    else:
        for next_v in linked_list[v]:
            if next_v not in used:
                used.append(next_v)
                dfs(next_v, n, used, linked_list)
                used.remove(next_v)
        return

def main():
    global ans
    n, m = map(int, input().split())
    linked_list = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        linked_list[a].append(b)
        linked_list[b].append(a)
    used = [1]
    dfs(1, n, used, linked_list)
    print(ans)

if __name__ == '__main__':
    main()