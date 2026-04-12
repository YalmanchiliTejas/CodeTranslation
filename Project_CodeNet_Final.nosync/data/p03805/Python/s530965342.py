import itertools

n, m = map(int, input().split())
ab = [0] * m
for i in range(m):
    a, b = map(int, input().split())
    ab[i] = (a, b)

ans = 0
pattern = list(itertools.permutations(list(range(2, n+1))))
for i in pattern:
    li = list(i)
    li.insert(0, 1)
    pattern_check = True
    for j in range(0, n-1):
        path_check = False
        for k in range(m):
            if len({li[j], li[j+1]} & set(ab[k])) == 2:
                path_check = True
                break
        if not path_check:
            pattern_check = False
            break
    if pattern_check:
        #print(li)
        ans += 1
print(ans)