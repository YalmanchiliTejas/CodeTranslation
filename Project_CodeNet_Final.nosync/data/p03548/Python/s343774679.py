X,Y,Z = map(int,input().split())
N = 0

while True:
    N += 1
    if X < (N+1)*Z + N * Y:
        break

print(N-1)