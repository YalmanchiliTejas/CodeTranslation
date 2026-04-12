n, x, m = map(int, input().split())

mn = min(n, m)
S = set()
A = []
a = x
sum_9 = 0 # sum of pre + cycle

for _ in range(mn):
    if a in S: break
    S.add(a)
    A.append(a)
    sum_9 += a
    a = a*a % m

if len(A) >= mn:
    print(sum_9)
    exit()

pre_len = A.index(a)
cyc_len = len(A) - pre_len
btm_len = (n - pre_len) % cyc_len

cyc_num = (n - pre_len) // cyc_len

pre = sum(A[:pre_len])
cyc = sum_9 - pre
btm = sum(A[pre_len: pre_len + btm_len])

print(pre + cyc * cyc_num + btm)
