scorelist = []

while 1:
    num, score = map(int, input().split(","))
    if num == 0 and score == 0:
        break

    scorelist.append(score)

score_unique = list(set(scorelist))
score_unique.sort(reverse=True)

while 1:
    try:
        q = int(input())
    except:
        break

    score = scorelist[q-1]

    for i, s in enumerate(score_unique):
        if score == s:
            print(i + 1)

