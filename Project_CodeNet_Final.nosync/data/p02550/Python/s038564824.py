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
    if a == 0:
        print(sum_9)
        exit()

if len(A) >= mn:
    print(sum_9)
    exit()

st_len = A.index(a)
cyc_len = len(A) - st_len
ed_len = (n - st_len) % cyc_len

cyc_num = (n - st_len) // cyc_len

pre = sum(A[:st_len])
cyc = sum_9 - pre
btm = sum(A[st_len: st_len + ed_len])

print(pre + cyc * cyc_num + btm)
