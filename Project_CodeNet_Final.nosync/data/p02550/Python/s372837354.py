n, x, m = map(int, input().split())
MAXM = 101010
visited = [-1 for _ in range(MAXM)]
a = x
loop = [a]
visited[a] = 0
ans = 0
for i in range(1, n):
    a = a**2%m
    if visited[a] < 0:
        visited[a] = i
        loop.append(a)
    else:
        ii = visited[a]
        l = sum(loop[ii:i]) # ループの和
        ll = i-ii # ループの長さ
        ans += sum(loop[:ii]) # ループに入るまでの和
        l_n = (n-ii)//ll # ループの回数
        ans += l*l_n
        rem = n-ii-ll*l_n # 残りの長さ
        ans += sum(loop[ii:rem+ii])
        break
if ans == 0:
    ans = sum(loop)
print(ans)