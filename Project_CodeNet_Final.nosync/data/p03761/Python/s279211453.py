n=int(input())
s=[[i for i in input()] for j in range(n)]
s_set=[list(set([i for i in s[j]])) for j in range(n)]
text=s_set[0]
for i in range(len(s_set)):
    text=text and s_set[i]
num=[0]*len(text)
for i in range(len(text)):
    mini=100000000000
    for j in range(len(s)):
        if s[j].count(text[i])<mini:
            mini=s[j].count(text[i])
    num[i]=mini
sorted_text=sorted(text)
ans=""
for i in sorted_text:
    for j in range(num[text.index(i)]):
        ans+=i
print(ans)