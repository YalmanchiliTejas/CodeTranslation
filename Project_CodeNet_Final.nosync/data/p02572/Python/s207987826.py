N = int(input())
A = [int(s) for s in input().split()]
mod = 10**9+7

wa = 0
wa_list = []
for i in range(N)[::-1]:
    if i == 0:
        break
    wa += A[i]
    wa_list.append(wa)

wa_list.reverse()
ans  = 0
for i in range(N-1):
    seki = A[i]*wa_list[i]
    ans += seki

print(ans % mod)