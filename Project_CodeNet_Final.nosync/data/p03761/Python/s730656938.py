import collections
n = int(input())
dic = []
for i in range(n):
    dic.append(collections.Counter(input()))
alp = [chr(i) for i in range(97,97+26)]
ans = ""
for x in alp:
    num = float("inf")
    for i in range(n):
        num = min(num,dic[i][x])
    ans += str(x)*num
print(ans)