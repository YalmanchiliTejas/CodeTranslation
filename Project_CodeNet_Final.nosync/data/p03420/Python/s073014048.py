import sys

stdin = sys.stdin
 
ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))
rs = lambda: stdin.readline().rstrip()  # ignore trailing spaces

N, K = rl()
answer = 0
if K == 0:
    print(N**2)
    exit()
for b in range(K+1, N+1):
    x = N // b
    answer += x * (b-K) + max(0, (N-(x*b))-K+1)
    #print(answer)

print(answer)
#59
