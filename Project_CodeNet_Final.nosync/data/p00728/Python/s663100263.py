while(1):
    n = int(input())
    if n == 0:
        break
    tmp = [int(input()) for i in range(n)]
    print(int((sum(tmp) - max(tmp) - min(tmp)) / (n - 2)))
