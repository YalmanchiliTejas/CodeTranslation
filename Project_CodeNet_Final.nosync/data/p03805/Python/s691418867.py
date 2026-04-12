import sys
input = sys.stdin.readline

N, M = map(int, input().split())
nums = [[] for _ in range(N)]
cou = 0

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    nums[a].append(b)
    nums[b].append(a)

def search(path):
    global cou
    n = path[len(path) - 1]
    if len(path) == N:
        cou += 1
    else:
        for x in nums[n]:
            if x not in path:
                path.append(x)
                search(path)
                path.pop()

search([0])
print(cou)