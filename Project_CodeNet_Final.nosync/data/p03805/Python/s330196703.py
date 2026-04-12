N,M = map(int,input().split())
dic = {i+1:[] for i in range(N)}

for i in range(M):
    f,g = map(int,input().split())
    dic[f].append(g)
    dic[g].append(f)


stack = [[1,1,[1]]]
root = 0
while len(stack) >0:
    now = stack[-1][0]
    length = stack[-1][1]
    visited = stack[-1][2]
    del stack[-1]
    for next in dic[now]:
        if next not in visited:
            temp = visited.copy()
            if length +1 <=N-1:
                temp.append(next)
                stack.append([next,length+1,temp])
            elif length +1 == N:
                root += 1


print(root)