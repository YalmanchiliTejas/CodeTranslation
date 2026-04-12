n = int(input())
s = [input() for i in range(n)]
lst = []
for i in range(ord("a"),ord("z")+1):
    m = 0
    for j in range(n):
        cnt = 0
        for k in range(len(s[j])):
            if i == ord(s[j][k]):
                cnt += 1
        if j == 0:
            m = cnt
        else:
            m = min(m, cnt)
    lst.append(m)

ans = ""
for i in range(26):
    ans += chr(ord("a")+i)*lst[i]

print(ans)