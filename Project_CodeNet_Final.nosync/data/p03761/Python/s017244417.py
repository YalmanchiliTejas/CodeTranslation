n = int(input())
# n, m = list(map(int, input().split()))
s = []
a = ""
_min = 50
for i in range(n):
    b = input()
    if len(b) <= _min:
        _min = len(b)
        a = b
    s.append(b)

for i in range(len(s)):
    if s[i] == a:
        s.pop(i)
        break

ans = []
for i in range(len(a)):
    flag = True
    for j in range(n-1):
        if a[i] in s[j]:
            for k in range(len(s[j])):
                if a[i] == s[j][k]:
                    s[j] = s[j][:k]+s[j][k+1:]
                    break
        else:
            flag = False

    if flag == True:
        ans += a[i]

ans.sort()
for a in ans:
    print(a, end="")

