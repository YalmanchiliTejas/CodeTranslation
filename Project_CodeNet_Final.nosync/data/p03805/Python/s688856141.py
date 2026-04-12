from copy import deepcopy as dp
N, M = map(int, input().split())
path = [list(map(int, input().split())) for i in range(M)]
count = 0

def ser(plase, path, ans):
    global count
    for i in range(len(path)):
        if path[i][0] == plase and not path[i][1] in ans:
            next_path = dp(path)
            next_path.pop(i)
            next_ans = dp(ans)
            next_ans.append(path[i][1])
            ser(path[i][1], next_path, next_ans)
        if path[i][1] == plase and not path[i][0] in ans:
            next_path = dp(path)
            next_path.pop(i)
            next_ans = dp(ans)
            next_ans.append(path[i][0])
            ser(path[i][0], next_path, next_ans)
    if N == len(ans):
        count += 1
ser(1, path, [1])
print(count)