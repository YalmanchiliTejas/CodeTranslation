from sys import stdin
import string
n = int(stdin.readline().rstrip())
w_dic = dict()
for i in string.ascii_lowercase:
    w_dic[i] = 0

dup = set(string.ascii_lowercase)
for _ in range(n):
    S = (stdin.readline().rstrip())
    dup = dup & set(S)
    for j in string.ascii_lowercase:
        if w_dic[j] == 0:
            w_dic[j] = S.count(j)
        else:
            w_dic[j] = min(w_dic[j],S.count(j))

ans = ""
dup = sorted(dup)
for k in dup:
    ans += (k*w_dic[k])
print(ans)