from itertools import permutations

n, m = map(int, input().split())
L = [set() for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    L[a-1].add(b-1)
    L[b-1].add(a-1)
lst = [i for i in range(1, n)]
ans = 0
for v in permutations(lst, n-1):
    case = [0] + list(v)
    for i in range(n-1):
        next = case[i+1]
        if next not in L[case[i]]:
            break
    else:
        ans += 1
print(ans)
