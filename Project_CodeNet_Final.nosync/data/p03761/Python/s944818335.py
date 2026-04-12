N = int(input())
S = [list(input()) for _ in range(N)]

result = S[0]
for i in range(1,N):
    temp = []
    for j in S[i]:
        if j in result:
            temp.append(j)
            result.remove(j)
    result = temp       
result.sort()
print("".join(result))
