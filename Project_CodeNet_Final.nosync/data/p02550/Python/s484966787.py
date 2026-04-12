N, X, M = map(int, input().split())
mod = M
A = [X]
AS = set()
AS.add(X)
cnt = 0
loop = -1
tail = -1
loop_sum = X
tail_sum = 0
while True:
    cnt += 1
    nex = pow(A[-1], 2, mod)
    if nex in AS:
        break
    A.append(nex)
    loop_sum += nex
    AS.add(nex)

for i, a in enumerate(A):
    if a == nex:
        tail = i
        loop = cnt - tail
        A = A[i:]
        break
    tail_sum += a
    loop_sum -= a

ans = tail_sum + (N - tail)//loop * loop_sum
N -= tail
N %= loop

for i in range(N):
    ans += A[i]

print(ans)