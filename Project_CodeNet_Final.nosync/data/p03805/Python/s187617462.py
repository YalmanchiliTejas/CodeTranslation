from itertools import permutations

N, M = map(int, input().split())
Hen = [[]for i in range(N)]


for i in range(M):
    a, b = map(int, input().split())
    Hen[a-1].append(b-1)
    Hen[b-1].append(a-1)

T = []
for i in range(1, N):
    T.append(i)

ans = 0
for I in permutations(T):
    flag = True
    S = [0]
    S.extend(I)
    for j in range(N-1):
        if S[j+1] not in Hen[S[j]]:
            flag = False
            break
    if flag:
        ans += 1

print(ans)
