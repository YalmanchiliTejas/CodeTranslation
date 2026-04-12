n=input()
s=input()
k=s[int(input())-1]
ans=""
for i in s:ans+= k if i==k else "*"
print(ans)