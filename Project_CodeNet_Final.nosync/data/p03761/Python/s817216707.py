N = int(input())
S = [0]*N
for i in range(N):
    S[i] = input()
# print(N, S)

T = []
for s in S:
    t = {}
    for i in range(26):
        t[chr(ord('a') + i)] = 0
    for a in s:
        t[a] += 1
    T.append(t)
# print(T)

ans = T[0]
for i in range(1, N):
    t = T[i]
    for j in range(26):
        k = chr(ord('a') + j)
        ans[k] = min(ans[k], t[k])
a = ''
for i in range(26):
    k = chr(ord('a') + i)
    a += k*ans[k]

print(a)
