n=int(input())
s=input()
k=int(input())

correct = s[k-1]
ans =""
for i in s:
    if i != correct:
        ans += "*"
    else:
        ans+= i

print(ans)
