n, m = map(int, input().split())
ab = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    ab[a - 1].append(b - 1)
    ab[b - 1].append(a - 1)
    
bin = [2 ** i for i in range(n + 1)]

def bfs(bit, pos, s):
    global ans
    if bit == bin[-1] - 1:
        ans += 1
        return
    for next_pos in ab[pos]:
        if (bit // bin[next_pos]) % 2 == 1:
            continue
        bfs(bit + bin[next_pos], next_pos, s + str(next_pos + 1))

ans = 0
bfs(1, 0, "1")
print(ans)