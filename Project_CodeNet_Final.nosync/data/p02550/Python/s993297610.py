N , X , M = map(int,input().split())
a = (X*X)%M
lis = [X]
while a not in lis:
    lis.append(a)
    a = a*a%M
i = lis.index(a)
lis1 = lis[:i]
lis2 = lis[i:]
ans=0
if N<=len(lis1):
    ans = sum(lis1[:N])
else:
    ans = sum(lis1)
    n = N - len(lis1)
    ans += (n//len(lis2))*sum(lis2)
    ans += sum(lis2[:n%len(lis2)])
#print(lis1)
#print(lis2)
print(ans)
