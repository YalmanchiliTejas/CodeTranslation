from collections import Counter
n = int(input())
Slist = [Counter(list(input())) for _ in range(n)]
ans = []
for i in range(ord("a"), ord("a") + 26):
    searching_alpha = chr(i)
    min_num = 10**9
    for S in Slist:
        min_num = min(min_num, S[searching_alpha])
    ans.append(searching_alpha * min_num)
print("".join(ans))
