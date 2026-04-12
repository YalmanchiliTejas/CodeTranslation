# encoding: utf-8
N, M = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(M)]

route = [[] for i in range(N)]
for ai, bi in ab:
    route[ai - 1].append(bi - 1)
    route[bi - 1].append(ai - 1)

# print("#", route)
    
def walk(pos, footprint):
    # goal
    if footprint == 2 ** N - 1: return 1
    # search route
    # print("##", pos, bin(footprint))
    ans = 0
    for to in route[pos]:
        if footprint & 2 ** to > 0: continue
        else: ans += walk(to, footprint + 2 ** to)
    return ans

print(walk(0, 1))