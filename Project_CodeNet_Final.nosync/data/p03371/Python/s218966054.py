a, b, c, x, y = map(int, input().split())
ans = []

for i in range(max(x+1, y+1)):
    tmp = c*i*2
    if i < x:
        tmp += a*(x-i)
    if i < y:
        tmp += b*(y-i)
    ans.append(tmp)

print(min(ans))