mod = 10**9 + 7
n = int(input())
A = list(map(lambda x: int(x) % mod, input().split()))

# out = 0
# for i in range(n - 1):
#     for j in range(n - i - 1):
#         k = i + j + 1
#         # print(A[i], A[k])
#         out += (A[i] * A[k])
#         out %= mod
B = A[1:n]
B_s = 0
for i in range(n - 1):
    B_s += B[i] % mod

out = 0
for i in range(n - 1):
    out += A[i] * B_s
    out %= mod
    B_s -= A[i + 1]
    B_s %= mod
    if B_s < 0:
        B_s += mod

print(out)
