import sys
F = sys.stdin
Continue = True
while Continue:
    N = int(F.readline().strip("\n"))
    if N == 0:
        Continue = False
        break
    else:
        Score = [None] * N
        for i in range(N):
            Score[i] = int(F.readline().strip("\n"))
        Score.sort()
        print(sum(Score[1:N-1])//(N-2)) 

