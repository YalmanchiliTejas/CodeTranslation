n = int(input())
a = list(map(int, input().split()))

bs = 10**9 + 7
s = sum(a)
sm = 0

for i, ai in enumerate(a):
    s -= ai
    sm += (ai * s) % bs
    sm = sm % bs

print(sm)