n, m = map(int, input().split())
p = [[] for i in range(n)]

for i in range(m):
    a, b = map(lambda x: int(x)-1, input().split())
    p[a].append(b)
    p[b].append(a)
ans = 0

# print(p)
def s(d, l):
    global ans
    # print(d,l)
    if d == n:
        ans += 1
        return
    for i in p[l[-1]]:
        if i in l:
            continue
        s(d+1, l+[i])
    return


s(1, [0])
print(ans)