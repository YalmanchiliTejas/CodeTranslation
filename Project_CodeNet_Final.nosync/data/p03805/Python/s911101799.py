N, M = map(int, input().split())

ab_list = []
for _ in range(M):
    ab_list.append(list(map(int, input().split())))

cnt = 0
def func(position, hist):
    global cnt
    hist = hist[:]
    if len(hist) == N:
        cnt += 1
    for ab in ab_list:
        if position in ab:
            next_position = [x for x in ab if x != position][0]
            if next_position not in hist:
                func(next_position, hist+[position])

func(1,[0])
print(cnt)