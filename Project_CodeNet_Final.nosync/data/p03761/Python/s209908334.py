from operator import itemgetter
import sys
n = int(input())
data = []
s = input()
if n == 1:
    L = list(s)
    L.sort()
    print("".join(L))
    sys.exit()
data.append(s)
S = set(list(s))
for i in range(n-1):
    s = input()
    S = S & set(list(s))
    data.append(s)
A = []
for i in S:
    ans = float("inf")
    for j in range(n-1):
        ans = min(ans,data[j].count(i))
    A.append([i,ans])
A.sort(key=itemgetter(0))
s = ""
for i in A:
    s += i[0]*i[1]
print(s)