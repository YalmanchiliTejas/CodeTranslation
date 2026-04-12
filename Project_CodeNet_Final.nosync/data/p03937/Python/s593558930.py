H, W = map(int, input().split())
c = 0
A = ['.' * (W + 2)]
for _ in range(H):
    a = input()
    c += a.count('#')
    A.append('.' + a + '.')
A.append('.' * (W + 2))

right = [0, 1]
under = [-1, 0]
goal = [H, W]
now = [1, 1]
ans = 1
while now != goal:
    if A[now[0] + 1][now[1]] == '#' and A[now[0]][now[1] + 1] == '#':
        break
    if A[now[0] + 1][now[1]] == '#':
        ans += 1
        now[0] += 1
    else:
        if A[now[0]][now[1] + 1] == '#':
            ans += 1
            now[1] += 1
        else:
            break

if ans == c:
    print('Possible')
else:
    print('Impossible')
