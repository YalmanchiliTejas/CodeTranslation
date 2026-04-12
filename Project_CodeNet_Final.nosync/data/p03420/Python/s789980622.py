N, K = map(int, input().split(' '))

ans = 0
for b in range(1, N+1):
    ans += max(b - K, 0) * (N // b)
    ans += max((N%b) - K + 1, 0)


if K == 0:
    ans -= N

print(ans)


# ans = 0
# for b in range(1, N+1):
#     for k in range(K, b):
#         for a in range(k, N+1, b):
#             if a > 0:
#                 ans += 1
#                 print(a, b)
#             else:
#                 pass
#                 # print(a, b)

# print(ans)
