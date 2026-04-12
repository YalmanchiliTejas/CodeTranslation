n = 1
while n != 0:
    n = int(input())
    S = []
    S = [int(input()) for _ in range(n)]
    if n==0:
        break
    ans = (sum(S)-min(S)-max(S))/(n-2)
    Ans = int(ans)
    print(Ans)

