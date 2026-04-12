import bisect
N = int(input())
A = [int(input()) for _ in range(N)]
B = []
for a in A:
    k = bisect.bisect(B, -a)
    if k == len(B):
        B.append(-a)
    else:
        B[k] = -a
print(len(B))