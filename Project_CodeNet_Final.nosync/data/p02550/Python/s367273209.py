# happendはsetで保持しておき，roopはlistで保持しておく
N, X, M = map(int, input().split())  # modMは10**5以下が与えられる
happend = set()
A = [X]
MOD = M
# 第1~N項まで計N項の和をもとめる
start = 0
for _ in range(N-1):
    if A[-1]**2 % MOD not in happend:
        happend.add(A[-1]**2 % MOD)
        A.append(A[-1]**2 % MOD)
    else:
        start = A.index(A[-1]**2 % MOD)
        break

roop_count = (N-start)//len(A[start:])

ans = sum(A[:start]) + sum(A[start:])*roop_count + sum(A[start:start+(N-start) % len(A[start:])])
# print(A[:start], A[start:], A[start:start+(N-start) % len(A[start:])])
print(ans)
