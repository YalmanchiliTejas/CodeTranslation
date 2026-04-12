n = int(input())
s = input()
k = int(input())

news=[]

tar = s[k-1]
for i in range(n):
    if s[i]!=tar:
        news += "*"
    else:
        news += s[i]

ans = ""        
for i in news:
    ans += i

print(ans)