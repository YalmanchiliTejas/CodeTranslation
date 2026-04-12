n = int(input())
s = list(input())
k = int(input())
e = s[k-1]
ans = []
for i in s:
    if i != e:
        ans.append("*")
    else:
        ans.append(i)
print("".join(ans))