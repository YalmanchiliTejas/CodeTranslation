def scoring():
    n = int(raw_input())
    if n is 0:
        return
    scores = [int(raw_input()) for _ in range(n)]
    scores.sort()
    if len(scores) < 2:
        return 0
    score = sum(scores[1:-1]) / (n-2)
    return score

while True:
    score = scoring()
    if score is None:
        break
    print score
        