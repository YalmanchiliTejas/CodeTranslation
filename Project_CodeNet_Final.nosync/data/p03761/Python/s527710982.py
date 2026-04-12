N=int(input())
S = [''] * N
for i in range(N):
    S[i] = input()

S_sorted = sorted(list(set(S[0])))

ans = ''
for c in S_sorted:
    count = min(S[i].count(c) for i in range(N))
    ans += c * count
 
print(ans)