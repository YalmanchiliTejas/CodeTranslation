from collections import *

n = int(input())
s_counted = Counter(input())

for i in range(n - 1):
    si_counted = Counter(input())
    for j in s_counted:
        if j in si_counted:
            s_counted[j] = min(s_counted[j], si_counted[j])

        else:
            s_counted[j] = 0

ans = ""
for i in sorted(s_counted.most_common()):
    ans += i[1] * i[0]

print(ans)