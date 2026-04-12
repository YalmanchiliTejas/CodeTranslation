while 1:
    score = []
    n = int(input())
    if n == 0:
        break
    for _ in range(n):
        score.append(int(input()))
    score.sort()
    del score[0]
    del score[-1]
    print(sum(score)//len(score)) 
