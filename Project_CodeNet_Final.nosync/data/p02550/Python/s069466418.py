n, x, m = map(int, input().split())
mn = min(n, m)
S = set()
A = []
a = x
ans = 0
for i in range(mn):
    if a in S: break
    S.add(a)
    A.append(a)
    ans += a
    a = a*a%m
    if a == 0:
        print(ans)
        exit()

# print(S)
# print(A)
# print(len(A), n, m)
if len(A) < mn:
    st_len = 0
    while st_len < len(A) and a != A[st_len]: st_len += 1
    st = sum(A[:st_len])
    cyc_sum = sum(A[st_len:])
    cyc_len = len(A) - st_len
    cyc_num = (n - st_len) // cyc_len
    # print('m {} n {} st_len {} cyc_len {} cyc_num {}'.format(m,n,st_len,cyc_len,cyc_num))
    cyc = cyc_sum * cyc_num
    ed_len = (n - st_len) % cyc_len
    ed = sum(A[st_len:][:ed_len])
    print(st + cyc + ed)
else:
    print(ans)
