import copy

n, x, m = map(int,input().split())

visited = [-1]*(m+1)
when = [-1]*(m+1)
ans = 0
i = 1
while i <= n:
    ans += x
    if x == 0:
        break
    if visited[x] > -1:
        cycle = (n - i) // (i - when[x])
        ans += cycle*(ans - visited[x])
        i += cycle*(i - when[x]) + 1
        visited = [-1]*(m+1)
        when = [-1]*(m+1)
        x **= 2
        x %= m    
        continue
    visited[x] = copy.deepcopy(ans)
    when[x] = copy.deepcopy(i)
    x **= 2
    x %= m
    i += 1


print(ans)