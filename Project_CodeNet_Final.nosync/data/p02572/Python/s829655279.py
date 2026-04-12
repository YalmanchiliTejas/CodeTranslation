N = int(input())
A = list(map(int,input().split()))

p_mod = (10**9)+7

A_sum = [A[0]]
a_before = A_sum[0]
for a in A[1:]:
    A_sum.append(a+a_before)
    a_before = a+a_before

ans=0
for n in range(N-1):
    ans += (A[n]%p_mod)*((A_sum[-1]%p_mod)-(A_sum[n]%p_mod))%p_mod
#     print(ans)
print(ans%p_mod)