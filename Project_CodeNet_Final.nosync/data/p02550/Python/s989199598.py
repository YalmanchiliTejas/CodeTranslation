from collections import defaultdict
N, X, M = map(int, input().split())
A = [X]
visited = set()
visited.add(X)

idx = defaultdict()
idx[X] = 0

iii = -1

for i in range(1, M):
    tmp = (A[-1]**2) % M
    if tmp not in visited:
        A.append(tmp)
        visited.add(tmp)
        idx[tmp] = i
    else:
        iii = idx[tmp]

# print(A)
# print(len(A))
# print(iii)

ans = 0

ans += sum(A[:iii])
N -= iii

l = len(A) - iii

ans += (N // l) * sum(A[iii:])
N -= N // l * l

ans += sum(A[iii:iii + N])

print(ans)
exit()
