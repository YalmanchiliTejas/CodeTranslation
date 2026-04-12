while True:
    n = int(input())
    score = []
    ans = 0
    if n==0:
        break
    for i in range(n):
        score.append(int(input()))
    score.sort()
    for i in range(1,len(score)-1):
        ans+=score[i]
    print(ans//(n-2))

