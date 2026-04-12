N, X, M = map(int, input().split())

def next_a(x):
    return pow(x, 2, M)

history = []
visited = set()

x = X
for _ in range(N):
    if x in visited:
        break
    visited.add(x)
    history.append(x)
    x = next_a(x)

if len(history) == N:
    # ループする前に終わる場合
    print(sum(history))
else:
    loop_start = history.index(x)
    loop_size = len(history) - loop_start
    loop_sum = sum(history[loop_start:])
    if ((N - len(history)) % loop_size) == 0:
        # ループぴったり
        print(sum(history) + loop_sum * ((N - len(history)) // loop_size))
    else:
        # ループが中途半端
        hasu = sum(history[loop_start:loop_start+((N - len(history)) % loop_size)])
        print(sum(history) + loop_sum * ((N - len(history)) // loop_size) + hasu)
