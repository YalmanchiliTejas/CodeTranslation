H, W = map(int, input().split())
S, U = [], []
for _ in range(H):
    s = list(input())
    if "#" in s: S.append(s)
T = list(zip(*S))
for i in range(W):
    if "#" in T[i]: U.append(T[i])
res = []
for t in zip(*U):
    res.append("".join(t))
print("\n".join(res))