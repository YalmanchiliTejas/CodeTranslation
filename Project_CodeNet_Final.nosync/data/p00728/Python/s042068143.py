averages = []

while True:
    amount = int(input())
    if amount == 0:
        break
    scores = [int(input()) for i in range(amount)]
    scores.remove(max(scores))
    scores.remove(min(scores))
    averages.append(sum(scores) // (amount - 2))

for i in range(len(averages)):
    print(averages[i])