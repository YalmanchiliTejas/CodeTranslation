n, m = map(int, input().split())
sides = [list(map(int, input().split())) for _ in range(m)]
check = [0] * n
ans = 0

def DFS(v):
    # print(v)
    if check.count(0) == 0:
        global ans
        ans += 1
        return
    for side in sides:
        if side[0] == v and check[side[1]-1] == 0:
            check[side[1]-1] = 1
            DFS(side[1])
            check[side[1]-1] = 0
        if side[1] == v and check[side[0]-1] == 0:
            check[side[0]-1] = 1
            DFS(side[0])
            check[side[0]-1] = 0
    return ans


check[0] = 1
print(DFS(1))

# procedure DFS(現在の頂点 v)
#     if 全ての頂点を訪問済み then
#         答えを 1 増やす。
#         return
#     end if
#     for 頂点 i: 頂点 v に隣接しているかつ未訪問 do
#         頂点 i を訪問済みとする。
#         DFS(i)
#         頂点 i を未訪問とする。
#      end for
#      return
#  end procedure
