n = int(input())

ans = list(input())
for i in range(n-1):
    memo = []
    S = input()
    for s in S:
        if s in ans:
            memo.append(s)
            ans.remove(s)
    ans = memo
print(*sorted(ans), sep='')
