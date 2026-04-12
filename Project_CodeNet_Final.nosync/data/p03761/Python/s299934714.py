n=int(input())
s=[input() for _ in range(n)]

ans=""
alphabets=list("abcdefghijklmnopqrstuvwxyz")
for alphabet in alphabets:
    tmp=51
    for si in s:
        tmp=min(tmp,si.count(alphabet))
    ans+=alphabet*tmp
print(ans)