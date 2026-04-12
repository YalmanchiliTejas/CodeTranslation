score = [[] for i in range(31)]
while True:
    try:
        p, s = map(int, input().split(","))
        if p == 0:
            break
        score[s].append(p)
    except:
        break

rank = {}
j = 1
for i in range(31)[::-1]:
    if len(score[i]) > 0:
        rank[i] = j
        j += 1

while True:
    try:
        p = int(input())
        for i in range(31):
            if p in score[i]:
                print(rank[i])
    except:
        break

