import sys
input = sys.stdin.readline
from operator import itemgetter

lis = []
n = 0
m = 0
ans = 0

def dfs(i, d, fr, used):
    global lis, ans
    if i in used:
        return
    if d == n - 1:
        ans += 1
        return
    for j in lis[i]:
        if j != fr:
            used.append(i)
            # print(i+1 , j+1)
            dfs(j, d+1, i, used)
            used.pop()


def main():
    global lis, n, m, ans
    n, m = map(int, input().strip().split())
    lis = [[] for _ in range(8)]
    for _ in range(m):
        a, b = list(map(lambda x: x-1, map(int, input().strip().split())))
        lis[a].append(b)
        lis[b].append(a)
    # print("##")
    dfs(0, 0, -1, [])
    print(ans)

if __name__ == '__main__':
    main()
