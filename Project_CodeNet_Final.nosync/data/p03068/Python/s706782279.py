n=int(input())
s = input()
k=int(input())

c = s[k-1]
news = ""
for i in range(n):
    if s[i] == c:
        news += c
    else:
        news += '*'
print(news)