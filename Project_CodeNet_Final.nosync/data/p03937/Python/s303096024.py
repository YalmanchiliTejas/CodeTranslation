import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

H,W = map(int,readline().split())

A = '.' * (W+2)
for _ in range(H):
    A += '.' + readline().rstrip().decode('utf-8') + '.'
A += '.' * (W+2)

start = 1 * (W+2) + 1
goal = H * (W+2) + W

v = start
fail = False
for _ in range(H+W-2):
    if A[v+1] == '#':
        v += 1
        continue
    elif A[v+W+2] == '#':
        v += (W+2)
        continue
    fail = True
    break

cnt = A.count('#')
bl = (cnt == H + W - 1) and (not fail)
answer = 'Possible' if bl else 'Impossible'
print(answer)