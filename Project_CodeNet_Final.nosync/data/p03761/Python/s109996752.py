n = int(input())
cnt = [ int(1e9) for i in range(26) ]
for i in range(n):
    s = input()
    nw = [ 0 for j in range(26) ]
    for j in s:
        nw[ord(j) - ord('a')]+=1
    for j in range(26):
        cnt[j] = min( cnt[j], nw[j] )
ans = ""
for i in range(26):
    if cnt[i] != int(1e9):
        ans += chr(i+97) * int(cnt[i])
print(ans)
