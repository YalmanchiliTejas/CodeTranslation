n = int(input())
S = list(input())
for _ in range(n-1):
    tmp = list(input())
    next_array = []
    for i in S:
        if i in tmp:
            next_array.append(i)
            tmp.remove(i)
    S = next_array
S.sort()
ans = ''
for i in S:
    ans += i
print(ans)
