n = int(input())
abt = [chr(i) for i in range(97, 97+26)]
lst = [str(input()) for i in range(n)]
ans = ""
for i in abt:
    l = []
    for j in lst:
        l.append(j.count(i))
    ans += i*min(l)
print(ans)