result = []
while True:
    no_referee = int(input())
    if no_referee == 0:
        break
    else:
        sum_score = 0
        max_score = 0
        min_score = 1000
        for i in range(no_referee):
            score = int(input())
            sum_score += score
            if score > max_score:
                max_score = score
            if score < min_score:
                min_score = score
        sum_score = sum_score - max_score - min_score
        result.append(int(sum_score/(no_referee-2)))

for r in result:
    print(str(r))
