N = int(input())
S = input().rstrip()
K = int(input())
char = S[K-1]
answer = ["*"]*N
next_index = 0
index_list = []
for i in range(N):
    now = S.find(char, next_index)
    if now == -1:
        break
    next_index = now + 1 
    index_list.append(now)
for i in index_list:
    answer[i] = char
print(*answer, sep="")
