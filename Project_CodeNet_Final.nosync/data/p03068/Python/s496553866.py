n = int(input())
s = input()
k = int(input())
ans = []
val = s[k-1]
for i in range(n):
    if s[i] != val:
        ans.append("*")
    else:
        ans.append(s[i])
a = ''.join(ans)
print(a)