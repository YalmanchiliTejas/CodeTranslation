n=int(input())
S=[]

for _ in range(n):
    s=input()
    vari=len(set(s))
    S.append([vari,s])

S.sort()   # 文字種類が少ない順にソート。
count={}   # 各文字の個数をカウント
elem=set(S[0][1])

for i in elem:
    count[i]=S[0][1].count(i)

for i in range(n-1):
    for j in elem:
        count[j]=min(count[j],S[i+1][1].count(j))

a=""
for i in count:
    a+=i*count[i]
a=sorted(list(a))
ans=""
for i in a:
    ans+=i
print(ans)
