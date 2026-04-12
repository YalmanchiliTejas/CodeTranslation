N, X = map(int, input().split())
burger_size = 1
patty_size = [1]
for _ in range(N):
    burger_size = burger_size*2+3
    patty_size.append(patty_size[-1]*2+1)
i = -2
ans = 0
left = 1
right = burger_size
for i in range(N, -1, -1):
    m = (left+right)//2
    if i == 0:
        ans += 1
        break
    elif left == X:
        break
    elif right == X:
        ans += patty_size[i-1]*2+1
        break
    elif m == X:
        ans += patty_size[i-1]+1
        break
    elif left < X < m:
        left += 1
        right = m-1
    else:
        ans += patty_size[i-1]+1
        left = m+1
        right -= 1

print(ans)
