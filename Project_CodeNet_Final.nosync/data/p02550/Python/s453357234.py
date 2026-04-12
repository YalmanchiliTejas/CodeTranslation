n, x, m = map(int, input().split())

mn = min(n, m)
S = set()
A = []
sum_9 = 0 # sum of pre + cycle

for _ in range(mn):
    if x in S: break
    S.add(x)
    A.append(x)
    sum_9 += x
    x = x*x % m

if len(A) >= mn:
    print(sum_9)
    exit()

pre_len = A.index(x)
cyc_len = len(A) - pre_len
nxt_len = (n - pre_len) % cyc_len

cyc_num = (n - pre_len) // cyc_len

pre = sum(A[:pre_len])
cyc = sum_9 - pre
nxt = sum(A[pre_len: pre_len + nxt_len])

print(pre + cyc * cyc_num + nxt)
