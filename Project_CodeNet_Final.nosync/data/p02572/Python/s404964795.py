N = int(input())
An = list(map(int, input().split()))
tt = sum(An)
total = tt
ans = 0
for A in An:
    At = A * (total-A)
#     if v == 1:
#         At = A * (tt-A)
#     else:
#         At = A * (tt-A*v)*v
#     print(A, total, At, ans)
#     md = At % (10**9+7)
    ans = (ans+At) % (10**9+7)
    total -= A
#     print(ans)
print(ans)







