cnt = 0

def dfs(v, n, used, linked_list):
    global cnt
    if len(used) == n:
        cnt += 1
        return
    else:
        for next_v in linked_list[v]:
            if next_v not in used:
                used.append(next_v)
                dfs(next_v, n, used, linked_list)
                used.remove(next_v)
        return

def main():
    global cnt
    n, m = map(int, input().split())
    linked_list = [[] for _ in range(n+1)]
    for i in range(m):
        a, b = map(int, input().split())
        linked_list[a].append(b)
        linked_list[b].append(a)
    used = [1]
    dfs(1, n, used, linked_list)
    print(cnt)

if __name__ == '__main__':
    main()
    
