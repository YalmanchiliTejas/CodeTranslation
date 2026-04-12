n = int(input())
s = input()
k = int(input())

let = s[k-1]

ans = ""
for i in range(n):
    x = s[i]
    if x == let:
        ans+=x
    else:
        ans += "*"
print(ans)