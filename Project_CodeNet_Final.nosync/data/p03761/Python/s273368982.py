n = int(input())
cnt = {c:50 for c in "abcdefghijklmnopqrstuvwxyz"}
for _ in [0]*n:
    cnt2 = {c:0 for c in "abcdefghijklmnopqrstuvwxyz"}
    S = input()
    for s in S:
        cnt2[s] += 1
    for c in cnt.keys():
        cnt[c] = min(cnt[c],cnt2[c])
ans = ""
for c,i in sorted(cnt.items()):
    ans += c*i
print(ans)