from collections import Counter
n=int(input())
dic=Counter(input())
for i in range(n-1):
    dic &=Counter(input())
ans=""
for i in sorted(dic.keys()):
    ans +=i*dic[i]
print(ans)