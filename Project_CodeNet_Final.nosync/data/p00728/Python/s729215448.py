ans = []
while True:
    n = int(input())
    if n == 0:
        break
    score = [int(input()) for i in range(n)]
    score.sort()
    ans.append(sum(score[1:-1]) // len(score[1:-1]))

for i in ans:
    print(i)
