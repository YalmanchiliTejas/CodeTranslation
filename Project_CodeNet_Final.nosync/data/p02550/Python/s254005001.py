N, X, M = map(int, input().split())

if N == 1:
    print(X)
    exit()

A = [-1] * (10**5 + 1)
A[1] = X

# %M は答えをMOD Mにしなさいといってくれているだけ
# M はたかだか10^5なので10^5繰り返すとどこかで循環する。循環するまで繰り返す。
S = set([X])
i = 2
while True:
    A[i] = ((A[i - 1])**2) % M
    if A[i] in S:
        break
    S.add(A[i])
    i += 1
# i -= 1
# print(f'{A[:20]=}, {S=}, {i=}')

end_idx = i - 1
start_idx = 0
for start_idx in range(i):
    if A[start_idx] == A[i]:
        break

num_circles = end_idx - start_idx + 1
# print(f'{start_idx=}, {end_idx=}, {num_circles=}')

A[0] = 0
if start_idx > N:
    ans = sum(A[:N + 1])
    print(ans)
    exit()

# print(f'{A[:20]=}')
# print(f'{A[:start_idx]=}')
v1 = sum(A[:start_idx])

remain_N = N - start_idx + 1
# print(f'{remain_N=}')

div, mod = divmod(remain_N, num_circles)
# print(f'{div=}, {mod=}')
# print(f'{A[start_idx:end_idx + 1]=}')
sum_circles = sum(A[start_idx:end_idx + 1])
# print(f'{sum_circles=}')

v2 = sum_circles * div

if mod == 0:
    v3 = 0
else:
    # print(f'{A[start_idx:start_idx + mod]=}')
    v3 = sum(A[start_idx:start_idx + mod])

ans = v1 + v2 + v3
print(ans)
