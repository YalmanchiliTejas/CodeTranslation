def dfs(A, chk):
    if a[A[-1][0]][A[-1][1]] == ".":
        return
    elif A[-1] == [h, w]:
        if len(A) == cnt and chk == 0:
            print("Possible")
        else:
            print("Impossible")
        exit()

    for v in [[1, 0], [0, 1], [0, -1], [-1, 0]]:
        tmp = [A[-1][0] + v[0], A[-1][1] + v[1]]
        if tmp not in A:
            A.append(tmp)
            if v in [[0, -1], [-1, 0]]:
                dfs(A, chk + 1)
            else:
                dfs(A, chk)                
            A.pop()

h, w = map(int, input().split())
a = [["."]*w]
a.extend([list("." + input() + ".") for x in range(h)])
a.append(["."]*w)
cnt = 0
for i in range(1,h+1):
    cnt += a[i].count("#")
dfs([[1, 1]], 0)
