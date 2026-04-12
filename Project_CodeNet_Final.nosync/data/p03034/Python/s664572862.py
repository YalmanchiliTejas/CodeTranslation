N = int(input())
S = list(map(int, input().split()))

ans = 0
for c in range(1, N):
    a = 0
    if (N-1) % c:
        for i in range(1, (N-1)//c):
            a += S[i*c] + S[N-1-i*c]
            ans = max(ans, a)
    else:
        se = set(list(range(N)))
        for i in range(1, (N-1)//c):
            if i*c not in se or N-1-i*c not in se or i*c == N-1-i*c:
                break
            se.remove(i*c)
            se.remove(N-1-i*c)
            a += S[i*c] + S[N-1-i*c]
            ans = max(ans, a)
print(ans)