n = int(input())
a =[chr(ord('a') + i) for i in range(26)]
ans = [10000]*26
for i in range(n):
    hindo = [0]*26
    s = input()
    for j in range(len(s)):
        hindo[a.index(s[j])] += 1
    for j in range(26):
        ans[j] = min(ans[j], hindo[j])
ans_ar = []
for i in range(26):
    tar = ans[i]
    for j in range(ans[i]):
        ans_ar.append(a[i])
print("".join(ans_ar))

